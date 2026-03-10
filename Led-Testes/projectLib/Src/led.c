#include "led.h"
#include <stdio.h>
#include <stm32c0xx_hal.h>
#include <stm32c0xx_hal_gpio.h>

#ifdef REHOST_TESTING
GPIO_PinState mock_PinState = GPIO_PIN_RESET;

void HAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN, GPIO_PinState state){}

void HAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN){}

GPIO_PinState HAL_GPIO_ReadPin(const GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN){
	if(GPIOA == GPIOx && GPIO_PIN == GPIO_PIN_8){
		printf("Button pressed\r\n");
		return mock_PinState;
	}
	return GPIO_PIN_SET;
}
#endif

void PushButton(int id){
	if(id == 8){
		if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8) == GPIO_PIN_RESET){
		  LedToggle(1);
		  LedToggle(2);
		}
	}
}

void LedToggle(int id){
	if(id == 1){
		HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_6);
		printf("Toggle led 1\r\n");
	}else{
		HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
		printf("Toggle led 2\r\n");
	}
}

void LedOn(int id){
	if(id == 1){
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);
		printf("Led %d acesso\r\n",id);
	}else{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);
		printf("Led %d acesso\r\n",id);
	}
}

void LedOff(int id){
	if(id == 1){
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);
		printf("Led %d apagado\r\n",id);
	}else{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);
		printf("Led %d apagado\r\n",id);
	}
}
