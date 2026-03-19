################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../projectLib/Src/adc.c \
../projectLib/Src/led.c \
../projectLib/Src/timer.c \
../projectLib/Src/uart.c 

OBJS += \
./projectLib/Src/adc.o \
./projectLib/Src/led.o \
./projectLib/Src/timer.o \
./projectLib/Src/uart.o 

C_DEPS += \
./projectLib/Src/adc.d \
./projectLib/Src/led.d \
./projectLib/Src/timer.d \
./projectLib/Src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
projectLib/Src/%.o projectLib/Src/%.su projectLib/Src/%.cyclo: ../projectLib/Src/%.c projectLib/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32C011xx -c -I../Core/Inc -I"C:/Users/santa/Embbebed/Led-Testes/projectLib/Src" -I../Drivers/STM32C0xx_HAL_Driver/Inc -I"C:/Users/santa/Embbebed/Led-Testes/projectLib/include/utils" -I../Drivers/STM32C0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32C0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-projectLib-2f-Src

clean-projectLib-2f-Src:
	-$(RM) ./projectLib/Src/adc.cyclo ./projectLib/Src/adc.d ./projectLib/Src/adc.o ./projectLib/Src/adc.su ./projectLib/Src/led.cyclo ./projectLib/Src/led.d ./projectLib/Src/led.o ./projectLib/Src/led.su ./projectLib/Src/timer.cyclo ./projectLib/Src/timer.d ./projectLib/Src/timer.o ./projectLib/Src/timer.su ./projectLib/Src/uart.cyclo ./projectLib/Src/uart.d ./projectLib/Src/uart.o ./projectLib/Src/uart.su

.PHONY: clean-projectLib-2f-Src

