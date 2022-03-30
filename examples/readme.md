# Examples for pico ssd1306 library

## Core library
| Link                                   | Description                                     |
|----------------------------------------|-------------------------------------------------|
| [bitmap_image](bitmap_image)           | Display a simple bitmap image                   |
| [falling_dots](falling_dots)           | Animation of dots falling on screen             |
| [write_mode](write_mode)               | Example showing differences between write modes |
| [multiple_displays](multiple_displays) | 2 Displays connected to the same i2c controller |

## Shape Renderer Module
| Link                   | Description                                                                   |
|------------------------|-------------------------------------------------------------------------------|
| [draw_line](draw_line) | Example of drawing a line across the screen                                   |
| [flag](flag)           | Drawing a "flag" on your display. Shows how to use different shape renderers. |


## Text Renderer Module
| Link                                       | Description                            |
|--------------------------------------------|----------------------------------------|
| [basic_text](basic_text)                   | Drawing some sample text to the screen |
| [text_advanced](text_advanced)             | Drawing normal and rotated text        |
| [text_extended_ascii](text_extended_ascii) | Using extended ASCII chars             |

## How to build an example

* Clone this project and go into one of the examples
```shell
git clone https://github.com/Harbys/pico-ssd1306.git
cd pico-ssd1306/examples/(choose_an_example)
```
* Copy pico_sdk_import.cmake from your pico-sdk
```shell
cp (path_to_pico_sdk)/external/pico_sdk_import.cmake .
```
* Set the PICO_SDK_PATH environment variable
```shell
export PICO_SDK_PATH="(path_to_pico_sdk)"
```
* Create a symlink to the whole library
```shell
ln -s ../../. pico-ssd1306
```
* Create a build directory and enter it
```shell
mkdir build
cd build
```
* Build
```shell
cmake .. && make
```
* Copy the uf2 file to your pico
