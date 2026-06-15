/*
* File: main.c
* Date: 06/15/2026
* Author: An Nguyen
* Description: C code for one LED blinking (Green - 12; Orange - 13; Red - 14; Blue - 15)
* CMSIS
*/

#include "stm32f4xx.h"

// Function for a delay
void delay(volatile uint32_t t)
{ 
    while (t--) {}
}

int main(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;

    GPIOD->MODER &= ~(3 << (12 * 2));
    GPIOD->MODER |= (1 << (12 * 2));

    while (1)
    {
        GPIOD->ODR ^1= (1 << 12);
        delay(100000);
    }
}