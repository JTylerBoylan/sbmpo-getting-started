#include <sbmpo/sbmpo.hpp>
#include <my_project/MyCustomModel.hpp>
#include <iostream>

using namespace my_namespace;

int main(int argc, char ** argv) {

  MyCustomModel model;

  sbmpo::SBMPOParameters params;
  /* Add in parameters here */
  params.max_iterations = 5000;
  params.max_generations = 100;
  params.start_state = {0, 0};
  params.goal_state = {10, 10};
  params.sample_time = 0.5f;
  params.grid_resolution = {0.25f, 0.25f};
  params.samples = {
    {1, 0}, {1, 1}, {0, 1}, {-1, 1},
    {-1, 0}, {-1, -1}, {0, -1}, {1, -1}
  };
  
  sbmpo::SBMPO planner(model, params);
  planner.run();
  
  std::cout << "-- Path --" << std::endl;
  std::vector<sbmpo::State> states = planner.state_path();
  std::vector<sbmpo::Control> controls = planner.control_path();
  for (size_t n = 0; n < states.size(); n++) {
    std::cout << " " << n << ") S:[ ";
    for (float s : states[n]) {
      std::cout << s << " ";
    }
    std::cout << "] C:[ ";
    if (n != states.size() - 1) {
      for (float c : controls[n]) {
        std::cout << c << " ";
      }
    }
      std::cout << "]" << std::endl;
  }

  std::cout << "---- Planner Results ----" << std::endl;
  std::cout << "Iterations: " << planner.iterations() << std::endl;
  std::cout << "Exit code: " << planner.exit_code() << std::endl;
  std::cout << "Computation Time: " << planner.time_us() << "us" << std::endl;
  std::cout << "Path cost: " << planner.cost() << std::endl;
  std::cout << "Number of nodes: " << planner.size() << std::endl;
  std::cout << "---------------" << std::endl;

  return 0;
}