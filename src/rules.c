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
bool warning_issued = false;
bool expired_issued = false;

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

// if a player is in the talking state and someone else is in the waiting state,
// increment the time_talking of the player.
static void update_talking_time()
{
    for (int i = 0; i < MAX_PLAYERS; i++)
    {
        if (players[i].addr != 0 && players[i].state == state_talking)
        {
            // track the total time the player has been talking
            ++players[i].time_total;
            for (int j = 0; j < MAX_PLAYERS; j++)
            {
                if (players[j].addr != 0 && players[j].state == state_waiting)
                {
                    // track the time the player has been talking since someone else has been waiting
                    ++players[i].time_talking;
                    return;
                }
            }
        }
    }
}

// warn the talking player if they have been talking for more than WARNING_TIME seconds
// if it has been more than EXPIRED_TIME seconds, send a cmd_talk_expired to all players
// after 2 more seconds, set the players state to state_listen and add 2 * EXPIRED_TIME to
// their time_total

void check_talk_time()
{
    // print the time_talking and time_total for each player every second
    if ((get_timer() % (1000 / TICK_INTERVAL_MS)) == 0)
    {
        printk("time:  (%d  %d),  (%d, %d), (%d, %d)\n",
               players[0].time_talking, players[0].time_total, players[1].time_talking, players[1].time_total, players[2].time_talking, players[2].time_total);
    }
    for (int i = 0; i < MAX_PLAYERS; i++)
    {
        if (players[i].addr != 0 && players[i].state == state_talking)
        {
            if (players[i].time_talking == SHUTUP_TIME)
            {
                broadcast_command(cmd_talk_expired_reset);
                private_command(players[i].addr, cmd_listening);
                players[i].state = state_listening;
                players[i].time_talking = 0;
                players[i].time_total += OVERTIME_PENALTY;
                printk("shutup issued\n");
            }
            else if (players[i].time_talking == EXPIRED_TIME)
            {
                broadcast_command(cmd_talk_expired);
                printk("expired issued\n");
            }
            else if (players[i].time_talking == WARNING_TIME)
            {
                private_command(players[i].addr, cmd_talk_warning);
                printk("warning issued\n");
            }
            else
            {
                // printk("time_talking: %d\n", players[i].time_talking);
            }
            return;
        }
    }
}

// The master has received a cmd_talk_request from a player.
// Add the player to the player array, then handle the request later
// in the state machine
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
        warning_issued = false;
        expired_issued = false;
        rules_init();
        break;

    case cmd_listening:
        state = state_listening;
        warning_issued = false;
        expired_issued = false;
        printk("time:  (%d  %d),  (%d, %d), (%d, %d)\n",
               players[0].time_talking, players[0].time_total, players[1].time_talking, players[1].time_total, players[2].time_talking, players[2].time_total);
        break;

    case cmd_waiting:
        state = state_waiting;
        break;

    case cmd_talk_request: // received by master from player
        set_talk_request(sender_addr, true);
        break;

    case cmd_talk_start:
        state = state_talking;

        printk("time:  (%d  %d),  (%d, %d), (%d, %d)\n",
               players[0].time_talking, players[0].time_total, players[1].time_talking, players[1].time_total, players[2].time_talking, players[2].time_total);

        break;

    case cmd_talk_warning:
        warning_issued = true;
        break;

    case cmd_talk_expired:
        // state = state_startup;
        expired_issued = true;
        break;

    case cmd_talk_expired_reset:
        warning_issued = false;
        expired_issued = false;
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
            players[i].time_talking = 0;
            players[i].talk_request = false;

            if (players[i].state == state_talking || players[i].state == state_waiting)
            {
                private_command(players[i].addr, cmd_listening);
                players[i].state = state_listening;
            }
            else
            {
                private_command(players[i].addr, cmd_waiting);
                players[i].state = state_waiting;
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
    update_talking_time();
    check_talk_time();

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

    if (expired_issued)
    {
        if ((get_timer() % BLINK_TIME) < (BLINK_TIME / 2))
        {
            set_led_left(RED);
            set_led_right(BLUE);
        }
        else
        {
            set_led_left(GREEN);
            set_led_right(RED);
        }
        return;
    }

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
    set_led_left(GREEN);
    set_led_right(BLUE);
}

static void talking_state()
{
    if (check_talk_button())
    {
        time_msg_sent = get_timer();
        private_command(master_addr, cmd_talk_request);
    }

    if (warning_issued)
    {
        set_led_left(RED);
        set_led_right(RED);
    }
    else
    {
        set_led_left(GREEN);
        set_led_right(GREEN);
    }
}

static void startup_state()
{
    set_led_left(RED);
    set_led_right(BLUE);
}
