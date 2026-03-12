#include "utils/led.h"
#include "utils/uart.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <stm32c0xx_hal.h>
#include <stm32c0xx_hal_gpio.h>


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
