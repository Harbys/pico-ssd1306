cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(multiple_displays)

pico_sdk_init()

add_subdirectory(pico-ssd1306)

add_executable(multiple_displays
        main.cpp)

target_link_libraries(multiple_displays
        hardware_i2c
        pico_ssd1306)


pico_add_extra_outputs(multiple_displays)
