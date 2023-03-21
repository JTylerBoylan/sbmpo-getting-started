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

## Creating a custom model
To plan trajectories using the SBMPO algorithm, you must first define a model for your robot.  To do this, you can use the template defined in [`my_project/include/my_project/MyCustomModel.hpp`](https://github.com/JTylerBoylan/sbmpo-getting-started/blob/main/my_project/include/my_project/MyCustomModel.hpp).

The model class comprises of 5 main functions that you'll need to edit:
- `next_state`: Determines a new state given the previous state, the control, and the time span using your robot kinematics.

- `cost`: Determines the cost of a point given its state and control, for which SBMPO will try to minimize.

- `heuristic`: Determines a heuristic of a point given its state and the goal state, which SBMPO will use to lead its search.

- `is_valid`: Determines if a point is valid given its state, which defines the bounds of the search space.

- `is_goal`: Determines if a point can be considered the goal, which will end the search when found true.

You can also define a constructor for your model that can be used to initialize parameters values, and setter functions to change the parameters.

Enums for States and Controls are included that can be used to track the indices of your State and Control vectors.

## Building the project
In `my_project_ws`:
```
mkdir build
cd build && cmake ..
make
```

## Renaming the project

## Using SBMPO Models

## Using SBMPO Benchmarking

