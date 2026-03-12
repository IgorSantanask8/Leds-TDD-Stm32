#include <CppUTestExt/MockSupport.h>
#include <cstdint>
#include <cstring>
#include <iostream>
#include "utils/led.h"
#include "utils/timer.h"
#include "utils/uart.h"

extern "C"{
	extern uint8_t last_sent_data[256];
	extern uint16_t last_sent_size ;
	extern bool uart_called;

	void sendMsg();
}

TEST_GROUP(uart){};

TEST(uart, Send){
	char message[] = "LED ON";
	sendMsg();
	CHECK_EQUAL(true, uart_called);
	STRCMP_EQUAL(message, (char*)last_sent_data);
	CHECK_EQUAL(6, last_sent_size);
}
