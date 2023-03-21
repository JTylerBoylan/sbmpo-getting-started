# SBMPO Getting Started

CMake project template for [Sample Based Model Predictive Optimization (SBMPO) for robot trajectory planning](https://github.com/JTylerBoylan/sbmpo).

## Dependencies
- [CMake 3.5](https://cmake.org/install/) or later
- [GCC 6.1](https://gcc.gnu.org/) or later

## Installation
To begin, clone this workspace to your directory of choice and pull down the sbmpo submodule using the following commands:
```
git clone https://github.com/JTylerBoylan/sbmpo-getting-started my_project_ws
git submodule update --init
```

## Creating a model

## Building
In `my_project_ws`:
```
mkdir build
cd build && cmake ..
make
```
