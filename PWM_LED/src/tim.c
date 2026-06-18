#include "tim.h"
#define TIM4EN (1U << 2)
#define CR1_CEN (1U << 0)

void tim4_init(void)
{
    RCC->APB1ENR |= TIM4EN; // Enable clock access of TIMx

    TIM4->PSC = 8399; // Set prescaler value
    TIM4->ARR = 100; // Sedt auto-reload value
    TIM4->CNT = 0; // Clear the counter

    TIM4->CCMR1 &= ~(7U << 4); // Set PWM mode
    TIM4->CCMR1 |= (6U << 4);
    TIM4->CCMR1 |= (1U << 3); // Enable preload

    TIM4->CCER |= (1U << 0); // Enable output

    TIM4->CR1 |= (1U << 7); 

    TIM4->EGR = 1; 
    TIM4->CR1 |= CR1_CEN; // Enable timer

    TIM4->CCR1 = 0; // Set initial brightness
}

void tim4_set_brightness(uint16_t value) // Set duty cycle
{
    if (value > 100){ 
        value = 100;
    }
    TIM4->CCR1 = value; // Duty cycle = CCR1/ARR
}

void tim4_start(void)
{
    TIM4->CR1 |= (1U << 0);
}

void tim4_end(void)
{
    TIM4->CR1 &= ~(1U << 0);
}