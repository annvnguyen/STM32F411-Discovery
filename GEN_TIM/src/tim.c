#include "tim.h"
#define TIM2EN (1U << 0)
#define CR1_CEN (1U << 0)

void tim2_1hz_init(void)
{
    RCC->APB1ENR |= TIM2EN; // Enable clock access of TIMx

    TIM2->PSC = 1600 - 1; // Set prescaler value
    TIM2->ARR = 10000 - 1; // Sedt auto-reload value
    TIM2->CNT = 0; // Clear the counter

    TIM2->CR1 = CR1_CEN; // Enable timer
    
}