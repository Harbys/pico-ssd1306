#include "pico/stdlib.h"
#include "pico-ssd1306/ssd1306.h"
#include "pico-ssd1306/textRenderer/TextRenderer.h"
#include "hardware/i2c.h"

// Use the namespace for convenience
using namespace pico_ssd1306;

int main(){
    // Init i2c0 controller
    i2c_init(i2c0, 1000000);
    // Set up pins 12 and 13
    gpio_set_function(12, GPIO_FUNC_I2C);
    gpio_set_function(13, GPIO_FUNC_I2C);
    gpio_pull_up(12);
    gpio_pull_up(13);

    // If you don't do anything before initializing a display pi pico is too fast and starts sending
    // commands before the screen controller had time to set itself up, so we add an artificial delay for
    // ssd1306 to set itself up
    sleep_ms(250);

    // Create a new display object at address 0x3D and size of 128x64
    SSD1306 display = SSD1306(i2c0, 0x3D, Size::W128xH64);

    // Here we rotate the display by 180 degrees, so that it's not upside down from my perspective
    // If your screen is upside down try setting it to 1 or 0
    display.setOrientation(0);

    drawText(&display, font_12x16, "Hello", 12, 0);
    drawText(&display, font_12x16, "World!", 48, 16);
    // Send buffer to the display
    display.sendBuffer();

    while (true) {
        display.setHorizontalScroll(ScrollDirection::Left, true, 0, 7, 0x00); // scroll left
        sleep_ms(6500);
        display.setHorizontalScroll(ScrollDirection::Right, true, 0, 7, 0x00); // scroll right
        sleep_ms(6500);
        display.setHorizontalScroll(ScrollDirection::Left, false); // turn scrolling off
        sleep_ms(5000);
    }
}
