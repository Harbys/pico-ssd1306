# Text Renderer Module
## This module provides functions for drawing chars and text on ssd1306 displays

## 1. Importing
```c++
#include "pico-ssd1306/textRenderer/TextRenderer.h"
```
note that core library and hardware_i2c library's need to be imported to use this library so follow steps from section 1
of [readme.md](../readme.md)

## 2. Differences from core library
Calling functions from modules is different from core lib. You can't just do ```object.drawText(...``` since modules don't
actually extend the SSD1306 class. You need to provide module functions with a pointer to a display object. So the first
argument of every module draw function is a pointer to a display.

To see this more clearly here is an example:
```c++
// Create a new display object
pico_ssd1306::SSD1306 display = pico_ssd1306::SSD1306(I2C_PORT, 0x3D, pico_ssd1306::Size::W128xH64);

// Draw some text
// Notice how we first pass the address of display object to the function
drawText(&display, font_12x16, "TEST text", 0 ,0);
```

## 3. Available fonts
This module comes with 4 fonts to choose from
* font_5x8 - 5px wide, 8px high font
* font_8x8 - 8px wide, 8px high font
* font_12x16 - 12px wide, 16px high font
* font_16x32 - 16px wide, 32px high font

Basic fonts support basic ASCII set chars (32-127), if you want to extended ASCII define
```c++
#define SSD1306_ASCII_FULL
```
at the top of your file

#### Note that using extended ASCII range increases project size

### Creating your own fonts
doing so is not that hard
a font is just a large array of bytes
```c++
const unsigned char font_16x32[] = {
        ...
};
```
the first 2 bytes are font's width and height
```c++
const unsigned char font_16x32[] = {
        0x10, 0x20, // font width, height
        ...
};
```
then followed by char data for ascii characters 32 - 126

Unlike bitmap images in the core library, fonts are scanned right to left, top to bottom

## All functions are documented [here](https://ssd1306.harbys.me)