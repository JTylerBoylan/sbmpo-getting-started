# SBMPO Getting Started

CMake project template for [Sample Based Model Predictive Optimization (SBMPO) for robot trajectory planning](https://github.com/JTylerBoylan/sbmpo).

## Dependencies
- [CMake 3.5](https://cmake.org/install/) or later
- [GCC 6.1](https://gcc.gnu.org/) or later

## Installation
To begin, clone this workspace to your directory of choice and pull down the sbmpo submodule using the following commands:
```
git clone https://github.com/JTylerBoylan/sbmpo-getting-started my_project_ws
cd my_project_ws
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

## Creating an executable
Once your model is defined, you can start using SBMPO to plan trajectories. To create an executable that uses SBMPO, you can use the template defined in [`my_project/src/main.cpp`](https://github.com/JTylerBoylan/sbmpo-getting-started/blob/main/my_project/src/main.cpp).

In your executable, you will have to set the SBMPO parameters for the run:
| Name | Description | Type |
| ---- | ----------- | ---- |
| `max_iterations` | Maximum branchout iterations | `int` |
| `max_generations` | Maximum branchout generations | `int` |
| `sample_time` | Time period per branchout | `float` |
| `grid_resolution` | Grid resolutions | `std::vector<float>` |
| `start_state` | Initial state of plan | `sbmpo::State` |
| `goal_state` | Goal state of plan | `sbmpo::State` |
| `samples` | List of controls to be sampled in a branchout | `std::vector<sbmpo::Control>` |


The template will then find the optimal path to the goal for your model and print out the results to the terminal.

## Building the project
The project comes with custom CMakeLists.txt files that will generate the CMake files for the project.

*Note that if you rename your project files, you will have to manually edit the CMakeLists.txt files in both the workspace and your project folder to match the changes.*

In the project workspace (*Default:* `my_project_ws`):
```
mkdir build && cd build
cmake .. && make
```

After building once, you only have to run the command `make` in the `build` folder to compile changes in the source code. However, if you make changes to the CMakeLists.txt files or make changes to the file structure, you will have to delete, then re-make the build folder.

## Running the executable
After the project has successfully been compiled, you can then run your executable using the following commands:
```
cd build/my_project
./my_executable
```
If you get segmentation faults during your run, you might want to check that your parameters are set correctly and that your start and goal states are the correct size.

## Using SBMPO Models

## Using SBMPO Benchmarking

