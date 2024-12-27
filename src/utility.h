#ifndef UTILITY_H__
#define UTILITY_H__

// colors
#define BLACK 0
#define BLUE 1
#define RED 2
#define MAGENTA 3
#define GREEN 4
#define CYAN 5
#define YELLOW 6
#define WHITE 7

#define MASTER_BTN 0x1
#define TALK_BTN 0x02


void timer_tick();
int get_timer();
bool timer_expired(int starttime, int duration);

int z_set_leds_state(uint32_t leds_on_mask, uint32_t leds_off_mask);
int z_leds_init(void);
void check_buttons(void);
void got_message(void);
void set_led_left(uint32_t val);
void set_led_right(uint32_t val);
bool isButtonPressed(uint32_t button);


#endif // UTILITY_H__