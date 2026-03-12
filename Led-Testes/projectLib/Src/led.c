#include "utils/led.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <stm32c0xx_hal.h>
#include <stm32c0xx_hal_gpio.h>

//Begining of UART mocks

uint8_t last_sent_data[256];
uint16_t last_sent_size = 0;
bool uart_called = false;

typedef struct{
	uint8_t Instance;
}UART_HandleTypeDef;

UART_HandleTypeDef huart1;

int HAL_UART_Transmit(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout){

	if(huart == &huart1){
		uart_called = true;
	 	 last_sent_size = Size;

	 	 if(Size <= 256){
	 		 memcpy(last_sent_data, pData, Size);
	 }
	 return 0;
	}
	return 1;
}

void sendMsg(){
	uint8_t msg[] = "LED ON";
	HAL_UART_Transmit(&huart1, msg, 6 ,100);
}

//End of Uart Mocks


GPIO_PinState mock_PinState = GPIO_PIN_RESET;

void HAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN, GPIO_PinState state){}

void HAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN){}

GPIO_PinState HAL_GPIO_ReadPin(const GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN){
	if(GPIOA == GPIOx && GPIO_PIN == GPIO_PIN_8){
		char msg[50] = "Button Pressed\r\n";
		printf(msg);
		return mock_PinState;
	}
	return GPIO_PIN_SET;
}


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
	}else{
		HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
	}
}

void LedOn(int id){
	if(id == 1){
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);
	}else{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);
	}
}

void LedOff(int id){
	if(id == 1){
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);
	}else{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);
	}
}
