# SysTick Delay Driver

**Description**

This project implements a delay function using the Cortex-M internal SysTick timer to generate accurate millisecond delays based on a 16 MHz system clock. The SysTick timer is configured to count down from a specified value corresponding to 1 ms, and the driver waits for the COUNTFLAG bit to be set - when the timer has reached zero. This process is then repeated for the requested number of milliseconds. 
