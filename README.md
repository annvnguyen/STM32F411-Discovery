# STM32F411 Discovery Projects

A collection of embedded systems projects developed using the **STM32F411 Discovery Board**, focused on understanding low-level ARM Cortex-M programming, peripheral control, and debugging techniques.

## Overview
The primary goal is to build a strong foundation in embedded systems development by working directly with registers and hardware.

Through these projects, I explore:
- ARM Cortex-M4 architecture
- CMSIS standards
- STM32 peripheral control (GPIO, UART, SPI, I2C, timer, ADC, etc.)
- Bare-metal firmware development

## Project Structure
| Project | Description |
|----------|-------------|
| [01 LED Blinking](./LED_BLINK) | Basic GPIO input/output control and register-level programming |
| [02 Button Interrupt](./EXTI_INTERRUPT) | External interrupt-based GPIO input handling using EXTI and NVIC |
| [03 SysTick Delay](./TIMER) | Combines GPIO control and the reusable SysTick delay function |
| [04 General-Purpose Timer](./GEN_TIM) | Uses TIM2 to generate a 1 Hz time base and toggle an LED at regular intervals |
| [05 PWM LED Fade](./PWM_LED) | Uses TIM4 PWM output to smoothly vary LED brightness by adjusting the duty cycle |
| [06 UART](./UART_TX) | Demonstrates UART serial communication by transmitting data from the microcontroller to a host device |

## Toolchain
- **Microcontroller:** STMF411 Discovery Board
- **IDE:** (STM32CUBEIDE / VSCode)
- **Language:** C
