#include "stm32f4xx.h"
#include "button_interrupt.h"

static void (*button_callback)(void) = 0;

void ButtonInterrupt_RegisterCallback(void (*cb)(void))
{
    button_callback = cb;
}

void ButtonInterrupt_Init(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;

    GPIOA->MODER &= ~(3U << (0 * 2)); // Configure button

    GPIOA->PUPDR &= ~(3U << (0 * 2));
    GPIOA->PUPDR |= (2U << (0 * 2));

    SYSCFG->EXTICR[0] &= ~(0xF << 0);

    EXTI->IMR |= (1U << 0); // Unmask interrupt
    EXTI->FTSR |= (1U << 0); // Enable rising edge
    EXTI->RTSR &= ~(1U << 0); // Disable falling edge

    NVIC_EnableIRQ(EXTI0_IRQn); // Enable NVIC
}

void EXTI0_IRQHandler(void)
{
    if(EXTI-> PR & (1U << 0))
    {
        EXTI->PR = (1U << 0);

        if(button_callback)
        {
            button_callback();
        }
    }
}
