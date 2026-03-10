################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../projectLib/Src/led.c 

OBJS += \
./projectLib/Src/led.o 

C_DEPS += \
./projectLib/Src/led.d 


# Each subdirectory must supply rules for building sources it contributes
projectLib/Src/%.o projectLib/Src/%.su projectLib/Src/%.cyclo: ../projectLib/Src/%.c projectLib/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32C011xx -c -I../Core/Inc -I"C:/Users/santa/Embbebed/Led-Testes/projectLib/Src" -I../Drivers/STM32C0xx_HAL_Driver/Inc -I"C:/Users/santa/Embbebed/Led-Testes/projectLib/include/utils" -I../Drivers/STM32C0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32C0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-projectLib-2f-Src

clean-projectLib-2f-Src:
	-$(RM) ./projectLib/Src/led.cyclo ./projectLib/Src/led.d ./projectLib/Src/led.o ./projectLib/Src/led.su

.PHONY: clean-projectLib-2f-Src

