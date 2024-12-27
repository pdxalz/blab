#include <string.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/device.h>
#include <zephyr/sys/util.h>
#include <dk_buttons_and_leds.h>

#include <zephyr/drivers/led_strip.h>
#include <zephyr/device.h>
#include <zephyr/drivers/spi.h>
#include <zephyr/drivers/pwm.h>
#include <zephyr/sys/util.h>

#include "rules.h"
#include "utility.h"
#include "model_handler.h"

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(rules, CONFIG_LOG_DEFAULT_LEVEL);

static void listen_state();
static void talking_state();
static void waiting_state();
static void startup_state();
static bool check_master_button();
static bool check_talk_button();

uint16_t master_addr = 0x0000;
uint16_t time_msg_sent = 0;

#define MAX_PLAYERS 10
struct players
{
    uint16_t addr;
    bool talk_request;
    int time_talking;
    int time_total;
    int state;
} players[MAX_PLAYERS];

enum turnz_state state = state_startup;

void rules_init()
{
    for (int i = 0; i < MAX_PLAYERS; i++)
    {
        players[i].addr = 0;
        players[i].time_talking = 0;
        players[i].time_total = 0;
        players[i].state = state_startup;
    }
}

void set_talk_request(uint16_t addr, bool request)
{
    for (int i = 0; i < MAX_PLAYERS; i++)
    {
        if (players[i].addr == addr)
        {
            players[i].talk_request = request;
            return;
        }
    }

    for (int i = 0; i < MAX_PLAYERS; i++)
    {
        if (players[i].addr == 0)
        {
            players[i].addr = addr;
            players[i].talk_request = request;
            return;
        }
    }
}

void turnzupMessages(char cmd, uint16_t sender_addr)
{
    switch (cmd)
    {
    case cmd_new_session:
        master_addr = sender_addr;
        state = state_listening;
        break;

    case cmd_listening:
        state = state_listening;
        break;

    case cmd_waiting:
        state = state_waiting;
        break;

    case cmd_talk_request: // received by master from player
        set_talk_request(sender_addr, true);
        break;

    case cmd_talk_start:
        state = state_talking;
        break;

    case cmd_talk_warning:
        break;

    case cmd_talk_expired:
        state = state_startup;
        break;

    default:
        break;
    }
}
static bool no_one_talking()
{
    for (int i = 0; i < MAX_PLAYERS; i++)
    {
        if (players[i].addr != 0 && players[i].state == state_talking)
        {
            return false;
        }
    }
    return true;
}

// for each player
//     if the player has a talk_request,
//          if they are talking, send them a cmd_listening and update their state
//          else send them a cmd_talk_start, update their state and return
static void master_handle_talk_requests()
{
    for (int i = 0; i < MAX_PLAYERS; i++)
    {
        if (players[i].addr != 0 && players[i].talk_request)
        {
            if (players[i].state == state_talking || players[i].state == state_waiting)
            {
                private_command(players[i].addr, cmd_listening);
                players[i].state = state_listening;
                players[i].talk_request = false;
            }
            else
            {
                // if no one is talking, start talking
                if (no_one_talking())
                {
                    private_command(players[i].addr, cmd_talk_start);
                    players[i].state = state_talking;
                    players[i].talk_request = false;
                    return;
                }
                else
                {
                    private_command(players[i].addr, cmd_waiting);
                    players[i].state = state_waiting;
                    players[i].talk_request = false;
                }
            }
        }
    }
}

// if no one is currently talking, search for the player that is waiting that has the shortest time_total
// and make them the new talker
static void set_new_talker()
{
    if (no_one_talking())
    {

        int min_time = 1000000;
        int min_index = -1;
        for (int i = 0; i < MAX_PLAYERS; i++)
        {
            if (players[i].addr != 0 && players[i].state == state_waiting && players[i].time_total < min_time)
            {
                min_time = players[i].time_total;
                min_index = i;
            }
        }

        if (min_index != -1)
        {
            private_command(players[min_index].addr, cmd_talk_start);
            players[min_index].state = state_talking;
        }
    }
}

void stateMachine()
{
    if (check_master_button())
    {
        time_msg_sent = get_timer();
        broadcast_command(cmd_new_session);
        // set each player to listening
        for (int i = 0; i < MAX_PLAYERS; i++)
        {
            players[i].state = state_listening;
        }
    }

    master_handle_talk_requests();
    set_new_talker();

    switch (state)
    {
    case state_startup:
        startup_state();
        break;

    case state_listening:
        listen_state();
        break;

    case state_waiting:
        waiting_state();
        break;

    case state_talking:
        talking_state();
        break;

    default:
        set_led_left(GREEN);
        set_led_right(BLUE);
        break;
    }
}

static bool check_master_button()
{
    return (isButtonPressed(MASTER_BTN) && timer_expired(time_msg_sent, 4));
}

static bool check_talk_button()
{
    return (isButtonPressed(TALK_BTN) && timer_expired(time_msg_sent, 4));
}

static void listen_state()
{
    if (check_talk_button())
    {
        time_msg_sent = get_timer();
        private_command(master_addr, cmd_talk_request);
    }
    set_led_left(BLUE);
    set_led_right(BLUE);
}

static void waiting_state()
{
    if (check_talk_button())
    {
        time_msg_sent = get_timer();
        private_command(master_addr, cmd_talk_request);
    }
    set_led_left(CYAN);
    set_led_right(CYAN);
}

static void talking_state()
{
    if (check_talk_button())
    {
        time_msg_sent = get_timer();
        private_command(master_addr, cmd_talk_request);
    }
    set_led_left(GREEN);
    set_led_right(GREEN);
}


static void startup_state()
{
    set_led_left(RED);
    set_led_right(GREEN);
}
