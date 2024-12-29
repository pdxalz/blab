#include <string.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/device.h>
#include <zephyr/sys/util.h>
#include <dk_buttons_and_leds.h>

#include <zephyr/device.h>
#include <zephyr/drivers/spi.h>
#include <zephyr/sys/util.h>

#include "rules.h"
#include "utility.h"
#include "model_handler.h"

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(utility, CONFIG_LOG_DEFAULT_LEVEL);

#define GPIO_SPEC_AND_COMMA(button_or_led) GPIO_DT_SPEC_GET(button_or_led, gpios),

#define ZLEDS_NODE DT_PATH(zleds)
static const struct gpio_dt_spec zleds[] = {
#if DT_NODE_EXISTS(ZLEDS_NODE)
    DT_FOREACH_CHILD(ZLEDS_NODE, GPIO_SPEC_AND_COMMA)
#endif
};

static int counter = 0;

void timer_tick()
{
    counter++;
}

int get_timer()
{
    return counter;
}

// return true if the timer has expired
bool timer_expired(int starttime, int duration)
{
    return (get_timer() - starttime) > duration;
}

// set LEDs on or off
int z_set_leds_state(uint32_t leds_on_mask, uint32_t leds_off_mask)
{
    if ((leds_on_mask & ~0x7f) != 0 ||
        (leds_off_mask & ~0x7f) != 0)
    {
        return -EINVAL;
    }

    for (size_t i = 0; i < ARRAY_SIZE(zleds); i++)
    {
        int val, err;

        if (BIT(i) & leds_on_mask)
        {
            val = 1;
        }
        else if (BIT(i) & leds_off_mask)
        {
            val = 0;
        }
        else
        {
            continue;
        }

        err = gpio_pin_set_dt(&zleds[i], val);
        if (err)
        {
            LOG_ERR("Cannot write LED gpio");
            return err;
        }
    }

    return 0;
}

// initialize the LEDs
int z_leds_init(void)
{
    int err;

    for (size_t i = 0; i < ARRAY_SIZE(zleds); i++)
    {
        err = gpio_pin_configure_dt(&zleds[i], GPIO_OUTPUT);
        if (err)
        {
            LOG_ERR("Cannot configure zLED gpio");
            return err;
        }
    }

    return z_set_leds_state(0, 0x3f);
}

// set the left LED
void set_led_left(uint32_t val)
{
    // hack to fix the bad left led on one board
    val = val | ((val & BLUE) << 6);
    z_set_leds_state(val, 0x47);
    //  z_set_leds_state(val, 0x47);
}

// set the right LED
void set_led_right(uint32_t val)
{
    z_set_leds_state(val << 3, 0x38);
}

// return true if the button is pressed
bool isButtonPressed(uint32_t button)
{
    uint32_t button_state = 0;
    dk_read_buttons(&button_state, NULL);
    return button_state & button;
}
