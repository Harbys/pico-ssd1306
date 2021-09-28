cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(write_mode)

pico_sdk_init()

add_subdirectory(pico-ssd1306)

add_executable(write_mode
        main.cpp)

target_link_libraries(write_mode
        hardware_i2c
        pico_ssd1306)


pico_add_extra_outputs(write_mode)