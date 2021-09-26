#include "pico/stdlib.h"
#include "pico-ssd1306/ssd1306.h"
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

    // Create a new display object at address 0x3D and size of 128x64
    SSD1306 display = SSD1306(i2c0, 0x3D, Size::W128xH64);

    // Here we rotate the display by 180 degrees, so that it's not upside down from my perspective
    // If your screen is upside down try setting it to 1 or 0
    display.setOrientation(0);

    // Create a variable storing out bitmap image
    unsigned char image[] = {
            0b00000001, 0b10000000,
            0b00000001, 0b10000000,
            0b00000011, 0b11000000,
            0b00000010, 0b01000000,
            0b00000110, 0b11100000,
            0b00001100, 0b00110000,
            0b00111001, 0b00011100,
            0b11101000, 0b01000111,
            0b11100010, 0b00000111,
            0b00111000, 0b01011100,
            0b00001100, 0b10110000,
            0b00000110, 0b01100000,
            0b00000011, 0b01000000,
            0b00000011, 0b11000000,
            0b00000001, 0b10000000,
            0b00000001, 0b10000000
    };


    // Add image to buffer with anchor at point x: 10, y:10 and image width: 16 and height:16
    display.addBitmapImage(10, 10, 16, 16, image);

    // Send buffer to the display
    display.sendBuffer();
}