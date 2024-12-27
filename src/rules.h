#ifndef RULES_H__
#define RULES_H__

enum turnz_cmd
{
    cmd_new_session = 'N',  // broadcast
    cmd_listening = 'L',    // private
    cmd_waiting = 'W',      // private
    cmd_talk_request = 'R', // private
    cmd_talk_start = 'T',   // private
    cmd_talk_warning = 'Y', // private
    cmd_talk_expired = 'X', // broadcast
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