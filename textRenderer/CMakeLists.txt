add_library(ssd1306_textRenderer
        TextRenderer.cpp
        5x8_font.h
        8x8_font.h
        12x16_font.h
        16x32_font.h
        )

target_link_libraries(ssd1306_textRenderer
        hardware_i2c
        pico_stdlib
        )