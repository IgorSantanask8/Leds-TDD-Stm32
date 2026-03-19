#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include <cstdint>
#include <cstring>
#include <iostream>
#include "utils/adc.h"



extern "C"{

	ADC_Start_HandleTypeDef static_adc;
	ADC_Start_HandleTypeDef *hadc1 = &static_adc;

	void HAL_ADC_PollForConversion(ADC_Start_HandleTypeDef *hadc){
		mock().actualCall("HAL_ADC_PollForConversion");
	}

	void checkTemperature(ADC_Start_HandleTypeDef *hadc){
		mock().actualCall("checkTemperature");
	}

	int HAL_ADC_Conversion(ADC_Start_HandleTypeDef *hadc){
		return mock().actualCall("HAL_ADC_Conversion")
				.withUnsignedIntParameter("channel_value", hadc->channel_value[hadc->last_channel])
				.withUnsignedIntParameter("last_channel" ,hadc->last_channel)
				.returnValue().getIntValue();
	}
}

TEST_GROUP(adc){
	void setup(){
		//
		hadc1->channel_value[0] = 50;
		hadc1->last_channel = 0;
	}
	void teardown(){
		mock().checkExpectations();
		mock().clear();
	}
};

TEST(adc, getValue){
	mock().expectOneCall("checkTemperature");

	mock().expectOneCall("HAL_ADC_Conversion")
		.withUnsignedIntParameter("channel_value", 50)
		.withUnsignedIntParameter("last_channel",0)
		.andReturnValue(0);


	checkTemperature(hadc1);

	int result = HAL_ADC_Conversion(hadc1);

 }
}
