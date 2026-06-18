#include "gpio.h"

#define GPIODEN (1U << 3)

void led_init(void)
{
    RCC->AHB1ENR |= GPIODEN;

    GPIOD->MODER &= ~(3 << (12 * 2));
    GPIOD->MODER |= (2 << (12 * 2));

    GPIOD->AFR[1] &= ~(0xFU << ((12 - 8) * 4));
    GPIOD->AFR[1] |= (2U << ((12 - 8) * 4));
}
