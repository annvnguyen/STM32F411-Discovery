#include "systick.h"

#define CTRL_ENABLE (1U << 0)
#define CTRL_CLCKSRC (1U << 2)
#define CTRL_COUNTFLAG (1U << 16) // Indicates when the timer has counted to 0

#define ONE_MS_LOAD 16000

void systick_ms_delay(uint32_t delay)
{
    SysTick->LOAD = ONE_MS_LOAD - 1; // Load the number of cycles per ms

    SysTick->VAL = 0; // Clear the current value

    SysTick->CTRL = CTRL_CLCKSRC; // Select internal clock source

    SysTick->CTRL |= CTRL_ENABLE; // Enable SysTick

    for (int i = 0; i < delay; i++)
    {
        while ((SysTick->CTRL & CTRL_COUNTFLAG) == 0) {}
    }

    SysTick->CTRL = 0; // Disable SysTick

}
