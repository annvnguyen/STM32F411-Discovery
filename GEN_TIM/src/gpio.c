#include "gpio.h"

#define GPIODEN (1U << 3)
#define LED_BS12 (1U << 12)
#define LED_BR12 (1U << (12 + 16))

void led_init(void)
{
    RCC->AHB1ENR |= GPIODEN;

    GPIOD->MODER &= ~(3 << (12 * 2));
    GPIOD->MODER |= (1 << (12 * 2));
}

void led_on(void)
{
    GPIOD->BSRR |= LED_BS12;
}

void led_off(void)
{
    GPIOD->BSRR |= LED_BR12;
}
