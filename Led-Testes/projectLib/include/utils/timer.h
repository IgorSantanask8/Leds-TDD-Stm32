#ifndef TIMER_H_
#define TIMER_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C"{
#endif

typedef struct{
	uint32_t Preescaler;
	uint32_t CounterMode;
	uint32_t Period;
	uint32_t ClockDivision;
	uint32_t RepetitionCounter;
	uint32_t AutoReloadPreload;
} TIM_BASE_InitTypeDef;

void InitTimer();

int HAL_TIM_BASE_Init(TIM_BASE_InitTypeDef *htim);

#ifdef __cplusplus
}
#endif

#endif
