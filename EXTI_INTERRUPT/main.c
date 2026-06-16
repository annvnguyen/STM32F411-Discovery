/*
* File: main.c
* Date: 06/16/2026
* Author: An Nguyen
* Description: Button interrupt controls LED
*/

#include "stm32f4xx.h"

void EXTI0_IRQHandler(void)
{
    if(EXTI->PR & (1 << 0))
    {
        GPIOD->ODR ^= (1 << 15);
        EXTI->PR = (1 << 0);
    }
}

int main(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; // Enable GPIO clock
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;

    GPIOD->MODER &= ~(3 << (15 * 2));
    GPIOD->MODER |= (1 << (15 * 2)); // Configure LED pin

    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN; //Enable button
    SYSCFG->EXTICR[0] &= ~(0xF); // Connect to EXTI0

    EXTI->IMR |= (1 << 0);
    EXTI->FTSR |= (1 << 0); //FTSR falling edge; RTSR rising edge

    NVIC_EnableIRQ(EXTI0_IRQn); // Enable interrupt in NVIC

    while(1)
    {

    }

}