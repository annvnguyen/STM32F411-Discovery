#include "tim.h"
#include "gpio.h"

void led_toggle(void)
{
    GPIOD->ODR ^= (1 << 12);
}

static void delay(volatile uint32_t t)
{
    while (t--) __asm__("nop");
}


int main(void)
{
    led_init();
    tim4_init();

    while (1)
    {
        for(int i = 0; i<=1000; i+= 2) {
            tim4_set_brightness(i);
            delay(3000);
        }

        for(int i = 1000; i>=0; i-=2) {
            tim4_set_brightness(i);
            delay(3000);
        }
    }
}