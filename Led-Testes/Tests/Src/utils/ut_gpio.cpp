#include <CppUTest/Testharness.h>
#include <iostream>
#include "utils/led.h"

TEST_GROUP(led){};

TEST(led, ledON){
	LedOn(1);
	LedOn(2);
}

TEST(led, ledoff){
	LedOff(1);
	LedOff(2);
}

TEST(led, ledToggle){
	LedToggle(1);
	LedToggle(2);
}

TEST(led, ledButton){
	PushButton(8);
}
