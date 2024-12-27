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

bool timer_expired(int starttime, int duration)
{
    return (get_timer() - starttime) > duration;
}

int z_set_leds_state(uint32_t leds_on_mask, uint32_t leds_off_mask)
{
    if ((leds_on_mask & ~0x3f) != 0 ||
        (leds_off_mask & ~0x3f) != 0)
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

void set_led_left(uint32_t val)
{
    z_set_leds_state(val, 0x07);
}

void set_led_right(uint32_t val)
{
    z_set_leds_state(val << 3, 0x38);
}

bool isButtonPressed(uint32_t button)
{
    uint32_t button_state = 0;
    dk_read_buttons(&button_state, NULL);
    return button_state & button;
}  


uint32_t button_old_state = 0;
void check_buttons(void)
{
    uint32_t button_state = 0;
    dk_read_buttons(&button_state, NULL);

    z_set_leds_state(button_state ? 8 : 0x10, 0x38);

    if (button_state != button_old_state)
    {
        button_old_state = button_state;
        if (button_state != 0)
        {
                       z_set_leds_state(button_state ? 0x30 : 0x20, 0x38);
//            broadcast_command("Hello");
            k_sleep(K_MSEC(1000));
        }
    }
}

void got_message(void)
{
    set_led_left(RED);
    set_led_right(GREEN);
    k_sleep(K_MSEC(1000));
}

// if (button_state != 0)
// {
// 	k_sleep(K_MSEC(1000));
// 	printk("Bluetooth init failed (err %d)\n", err);
// }
