#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include <cstdint>
#include <cstring>
#include <iostream>
#include "utils/led.h"
#include "utils/timer.h"

extern "C"{

	extern TIM_BASE_InitTypeDef htim3;

	void InitTimer();

	int HAL_TIM_BASE_Init(TIM_BASE_InitTypeDef *htim){
		return mock().actualCall("HAL_TIM_BASE_Init")
				.withUnsignedIntParameter("Preescaler", htim->Preescaler)
				.withUnsignedIntParameter("Period",htim->Period)
				.returnValue().getIntValue();//HALOK
	}
}

TEST_GROUP(timer){
	void setup(){
		//
	}
	void teardown(){
		mock().checkExpectations();
		mock().clear();
	}
};

TEST(timer, InicializeTimer){
	mock().expectOneCall("HAL_TIM_BASE_Init")
			.withUnsignedIntParameter("Preescaler",48000-1)
			.withUnsignedIntParameter("Period",1000-1)
			.andReturnValue(0);

	InitTimer();

}
