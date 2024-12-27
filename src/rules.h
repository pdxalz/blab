#ifndef RULES_H__
#define RULES_H__

#define TICK_INTERVAL_MS 50

#define WARNING_TIME (7 * 1000 / TICK_INTERVAL_MS)
#define EXPIRED_TIME (10 * 1000 / TICK_INTERVAL_MS)
#define SHUTUP_TIME (13 * 1000 / TICK_INTERVAL_MS)
#define BLINK_TIME (500 / TICK_INTERVAL_MS)
#define MAX_PLAYERS 10

enum turnz_cmd
{
    cmd_new_session = 'N',  // broadcast
    cmd_listening = 'L',    // private
    cmd_waiting = 'W',      // private
    cmd_talk_request = 'R', // private
    cmd_talk_start = 'T',   // private
    cmd_talk_warning = 'X', // private
    cmd_talk_expired = 'Y', // broadcast
    cmd_talk_expired_reset = 'Z', // broadcast
};

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