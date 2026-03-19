cmake_minimum_required(VERSION 3.22)

add_library(projectLib OBJECT
 src/led.c
 src/timer.c
 src/adc.c
)

target_compile_definitions(projectLib PUBLIC STM32C011xx)

target_include_directories(projectLib
 PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/include

  ${CMAKE_SOURCE_DIR}/Core/Inc
  ${CMAKE_SOURCE_DIR}/Drivers/STM32C0xx_HAL_DRIVER/Inc
  ${CMAKE_SOURCE_DIR}/Drivers/STM32C0xx_HAL_DRIVER/Inc/Legacy
  ${CMAKE_SOURCE_DIR}/Drivers/CMSIS/DEVICE/ST/STM32C0xx/Include
  ${CMAKE_SOURCE_DIR}/Drivers/CMSIS/Include
)