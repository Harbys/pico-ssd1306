cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(falling_dots)

pico_sdk_init()

add_subdirectory(pico-ssd1306)

add_executable(falling_dots
        main.cpp)

target_link_libraries(falling_dots
        hardware_i2c
        pico_ssd1306)


pico_add_extra_outputs(falling_dots)
