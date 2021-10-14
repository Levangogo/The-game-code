#ifndef __TIM5_H
#define __TIM5_H

#include "stm32f4xx.h" 

typedef struct
{
	u16 task_counter_60000ms;
}TASK_COUNTER;

void TIM5_Init(void);

#endif
