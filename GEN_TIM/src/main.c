#include "tim.h"
#include "gpio.h"

void led_toggle(void)
{
    GPIOD->ODR ^= (1 << 12);
}


int main(void)
{
    led_init();
    tim2_1hz_init();

    while (1)
    {
        led_toggle();
        while (!(TIM2->SR & SR_UIF)) {}
        TIM2->SR &=~SR_UIF;
    }
}