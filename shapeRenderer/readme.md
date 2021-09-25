# Shape Renderer Module
## This module provides functions for drawing basic geometrical shapes with simple code

## 1. Importing
```c++
#include "pico-ssd1306/shapeRenderer/ShapeRenderer.h"
```
note that core library and hardware_i2c library's need to be imported to use this library so follow steps from section 1
of [readme.md](../readme.md)

## 2. Differences from core library
Calling functions from modules is different from core lib. You can't just do ```object.drawLine(...``` since modules don't
actually extend the SSD1306 class. You need to provide module functions with a pointer to a display object. So the first
argument of every module draw function is a pointer to a display.

To see this more clearly here is an example:
```c++
// Create a new display object
pico_ssd1306::SSD1306 display = pico_ssd1306::SSD1306(I2C_PORT, 0x3D, pico_ssd1306::Size::W128xH64);

// Draw a line from x: 0, y: 0 to x: 128, y: 64
// Notice how we first pass the address of display object to the function
pico_ssd1306::drawLine(&display, 0, 0, 128, 64);

```

## All functions are documented [here](https://ssd1306.harbys.me)