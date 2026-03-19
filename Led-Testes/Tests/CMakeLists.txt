cmake_minimum_required(VERSION 3.22)

add_executable(test_on_host
 src/main_test.cpp
 src/utils/ut_gpio.cpp
 src/utils/ut_timer.cpp
 src/utils/ut_uart.cpp
 src/utils/ut_adc.cpp
)

target_include_directories(test_on_host
 PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(test_on_host
 projectLib
 CppUTest
 CppUTestExt
)

include(FetchContent)
FetchContent_Declare(
    CppUTest
    GIT_REPOSITORY https://github.com/cpputest/cpputest.git
    GIT_TAG        master
    SOURCE_DIR     "${CMAKE_SOURCE_DIR}/thirdy-party/cpputest"       
)
FetchContent_MakeAvailable(CppUTest)
 