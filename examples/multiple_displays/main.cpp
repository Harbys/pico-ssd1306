#include "pico/stdlib.h"
#include "pico-ssd1306/ssd1306.h"
#include "pico-ssd1306/textRenderer/TextRenderer.h"
#include "hardware/i2c.h"

// Use the namespace for convenience
using namespace pico_ssd1306;

int main() {
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

    // Create a new display object at address 0x3C and size of 128x32
    SSD1306 display1 = SSD1306(i2c0, 0x3C, Size::W128xH32);

    // Create a new display object at address 0x3D and size of 128x64
    SSD1306 display2 = SSD1306(i2c0, 0x3D, Size::W128xH64);

    // Here we rotate the display by 180 degrees, so that it's not upside down from my perspective
    // If your screen is upside down try setting it to 1 or 0
    display1.setOrientation(0);
    display2.setOrientation(0);

    // Draw text on display 1
    drawText(&display1, font_16x32, "Disp 1", 0, 0);

    // Draw text on display 2
    drawText(&display2, font_16x32, "Disp 2", 0, 0);

    // Send buffer to the displays
    display1.sendBuffer();
    display2.sendBuffer();

}
