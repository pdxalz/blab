#ifndef RULES_H__
#define RULES_H__

#define TICK_INTERVAL_MS 50
#define CLICK_TIME (1000 / TICK_INTERVAL_MS) // time until another click is allowed
#define WARNING_TIME (30 * 1000 / TICK_INTERVAL_MS) // time until warning is issued
#define EXPIRED_TIME (40 * 1000 / TICK_INTERVAL_MS) // time until expired is issued
#define SHUTUP_TIME (43 * 1000 / TICK_INTERVAL_MS)  // time until flashing ends
#define BLINK_TIME (500 / TICK_INTERVAL_MS)
#define OVERTIME_PENALTY (100 * 1000 / TICK_INTERVAL_MS) // extra time added for not shutting up
#define MAX_PLAYERS 10

// commands sent in messages
enum turnz_cmd
{
    cmd_new_session = 'N',        // broadcast
    cmd_listening = 'L',          // private
    cmd_waiting = 'W',            // private
    cmd_talk_request = 'R',       // private
    cmd_talk_start = 'T',         // private
    cmd_talk_warning = 'X',       // private
    cmd_talk_expired = 'Y',       // broadcast
    cmd_talk_expired_reset = 'Z', // broadcast
};

// states of the players
enum turnz_state
{
    state_startup,
    state_listening,
    state_waiting,
    state_talking,
};

void rules_init();
void turnzupMessages(char cmd, uint16_t sender_addr);
void stateMachine();

#endif // RULES_H__