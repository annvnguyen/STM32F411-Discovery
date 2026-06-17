#include "stm32f4xx.h"

void led_toggle(void)
{
    GPIOD->ODR ^= (1 << 12);
}

int main(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;

    GPIOD->MODER &= ~(3 << (12 * 2));
    GPIOD->MODER |= (1 << (12 * 2));

    while (1)
    {
        systick_ms_delay(200);
        led_toggle();
    }
}