
cmake_minimum_required(VERSION 3.12)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

project(pico-ssd1306
    VERSION 1.0.0
    DESCRIPTION "SSD1306 Library for RP2040"
)

add_library(pico-ssd1306 INTERFACE
        ssd1306.cpp
        frameBuffer/FrameBuffer.cpp
        shapeRenderer/ShapeRenderer.cpp)

add_subdirectory(textRenderer)

target_sources(pico-ssd1306 INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/ssd1306.cpp
)

target_include_directories(pico-ssd1306 INTERFACE ${CMAKE_CURRENT_LIST_DIR})

# Link to pico_stdlib (gpio, time, etc. functions)
target_link_libraries(${PROJECT_NAME} INTERFACE
    hardware_i2c
)