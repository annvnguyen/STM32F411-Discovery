#include "stm32f4xx.h"
#ifndef TIM_H_
#define TIM_H_

#define SR_UIF (1U << 0)
void tim4_init(void);
void tim4_set_brightness(uint16_t value);
void tim4_start(void);
void tim4_end(void);

#endif