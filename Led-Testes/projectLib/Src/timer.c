#include "utils/timer.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <stm32c0xx_hal.h>
#include <stm32c0xx_hal_gpio.h>



TIM_BASE_InitTypeDef htim3;

void InitTimer(){
	htim3.Preescaler = 48000-1;
	htim3.Period = 1000-1;

	HAL_TIM_BASE_Init(&htim3);
}
