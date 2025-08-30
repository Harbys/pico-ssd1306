cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(scrolling_example)

pico_sdk_init()

add_subdirectory(pico-ssd1306)

add_executable(scrolling_example
        main.cpp)

target_link_libraries(scrolling_example
        hardware_i2c
        pico_ssd1306)


pico_add_extra_outputs(scrolling_example)
