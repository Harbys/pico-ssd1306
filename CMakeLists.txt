add_library(pico_ssd1306
        ssd1306.cpp
        frameBuffer/FrameBuffer.cpp
        shapeRenderer/ShapeRenderer.cpp)

add_subdirectory(textRenderer)

target_link_libraries(pico_ssd1306
        ssd1306_textRenderer
        hardware_i2c
        pico_stdlib
        )
target_include_directories (pico_ssd1306 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})