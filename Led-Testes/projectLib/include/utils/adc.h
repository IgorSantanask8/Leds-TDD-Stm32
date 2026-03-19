#ifndef ADC_H_
#define ADC_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C"{
#endif

typedef struct {
	uint32_t channel_value[16];
	bool conversion;
	int last_channel;
} ADC_Start_HandleTypeDef;

void HAL_BASE_Start(ADC_Start_HandleTypeDef *hadc);

uint32_t HAL_ADC_GetValue(ADC_Start_HandleTypeDef *hadc);

extern ADC_Start_HandleTypeDef *hadc1;

#ifdef __cplusplsus
}
#endif

#endif //ADC_H_
