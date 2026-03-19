#include "utils/adc.h"
#include "utils/uart.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stm32c0xx_hal.h>
#include <stm32c0xx_hal_gpio.h>


void HAL_BASE_Start(ADC_Start_HandleTypeDef *hadc){
	hadc->conversion = true;
}

uint32_t HAL_ADC_GetValue(ADC_Start_HandleTypeDef *hadc){
	hadc->conversion = false;

	return hadc->channel_value[hadc->last_channel];
}

//void checkTemperature(ADC_Start_HandleTypeDef *hadc){
//	hadc->last_channel = 0;
//	hadc->channel_value[0] = 50;
//
//	if(hadc->channel_value[0]>= 50){
//		printf("Valor alto, deligando operacoes para resfriamento");
//	}else{
//		printf("Temperatura ok");
//	}
//}

