#ifndef __TIMER_H
#define __TIMER_H

void Timer_Init(void);
uint16_t Timer_GetCounter(void);
uint16_t Timer_GetCounter1(void);
void TIM2_IRQHandler(void);
uint64_t GetPreciseTimeUs(void);

#endif
