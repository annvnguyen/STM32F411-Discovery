#ifndef BUTTON_INTERRUPT_H
#define BUTTON_INTERRUPT_H

void ButtonInterrupt_Init(void);
void ButtonInterrupt_RegisterCallback(void (*cb)(void));

#endif
