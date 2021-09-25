# Examples for pico ssd1306 library

## Core library
| Link         | Description |
|--------------|-------------|
|              |             |

## Shape Renderer Module
| Link                 | Description |
|----------------------|-------------|
|[draw_line](draw_line)|Example of drawing a line across the screen|


## Text Renderer Module
| Link         | Description |
|--------------|-------------|
|              |             |

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
export export PICO_SDK_PATH="(path_to_pico_sdk)"
```
* Create a build directory and enter it
```shell
mkdir build
cd build
```
* Build
```shell
cmake ..
```
* Copy the uf2 file to your pico