/*
* File: main1.c
* Date: 06/15/2026
* Author: An Nguyen
* Description: C code for controlling LEDs using GPIO pins and reading input from a button
* Manual register style
*/

#include "stm32f4xx.h"

#define LED_GREEN 12
#define LED_ORANGE 13
#define LED_RED 14
#define LED_BLUE 15
#define BUTTON 0

// Function for a delay
void delay(volatile uint32_t t)
{ 
    while (t--) {}
}

// Function to initialize GPIO pins
void GPIO_Init(void)
{
    volatile unsigned int *RCC_AHB1ENR = (volatile unsigned int *)0x40023830;
    *RCC_AHB1ENR |= (1 << 3); //Enable clock for GPIO D
    *RCC_AHB1ENR |= (1 << 0); //Enable clock for GPIO A

    // Configure LED pin as output
    volatile unsigned int *GPIOD_MODER = (volatile unsigned int *)0x40020C00;
    *GPIOD_MODER |= (1 << (LED_GREEN * 2));
    *GPIOD_MODER |= (1 << (LED_ORANGE * 2));
    *GPIOD_MODER |= (1 << (LED_RED * 2));
    *GPIOD_MODER |= (1 << (LED_BLUE * 2));

    // Configure button as input
    volatile unsigned int *GPIOA_MODER = (volatile unsigned int*)0x40020000;
    *GPIOA_MODER &= ~(3 << (BUTTON * 2));
}

// Function to toggle pins
void GPIO_TogglePin()
{
    volatile unsigned int *GPIOD_ODR = (volatile unsigned int *)0x40020C14;
    *GPIOD_ODR ^= (1 << LED_GREEN);
    *GPIOD_ODR ^= (1 << LED_ORANGE);
    *GPIOD_ODR ^= (1 << LED_RED);
    *GPIOD_ODR ^= (1 << LED_BLUE);
}

int main(void) {
    GPIO_Init();

    while (1) {
        volatile unsigned int *GPIOA_IDR = (volatile unsigned int *)0x40020010; // Read input from button
        if (!(*GPIOA_IDR & (1 << BUTTON))) {
            delay(100000);
        } else {
            delay(1000000);
        }

        GPIO_TogglePin();
    }
}