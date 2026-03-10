cmake_minimum_required(VERSION 3.22)

set(CMAKE_G_FLAGS -m32)
set(CMAKE_CXX_FLAGS -m32)

project(Led_Testes LANGUAGES C CXX)

add_subdirectory(projectLib)

add_subdirectory(Tests)

target_link_libraries(projectLib
)
