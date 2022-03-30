cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(text_extended_ascii)

pico_sdk_init()

add_subdirectory(pico-ssd1306)

add_executable(text_extended_ascii
        main.cpp)

target_link_libraries(text_extended_ascii
        hardware_i2c
        pico_ssd1306)


pico_add_extra_outputs(text_extended_ascii)
