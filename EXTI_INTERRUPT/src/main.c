/*
* File: main.c
* Date: 06/16/2026
* Author: An Nguyen
* Description: Button interrupt driver (Bare Metal)
*/

#include "stm32f4xx.h"

void LedToggle(void)
{
    GPIOD->ODR ^= (1 << 15);
}

int main(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;

    GPIOD->MODER &= ~(3U << (15 * 2));
    GPIOD->MODER |=  (1U << (15 * 2));

    ButtonInterrupt_Init();

    ButtonInterrupt_RegisterCallback(LedToggle);

    while(1)
    {
    }

}
