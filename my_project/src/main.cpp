#include <sbmpo/SBMPO.hpp>
#include <my_project/MyCustomModel.hpp>
#include <sbmpo/tools/PrintTool.hpp>

using namespace my_namespace;

int main(int argc, char ** argv) {

  sbmpo::SearchParameters params;
  /* Add in parameters here */
  params.max_iterations = 5000;
  params.max_generations = 100;
  params.start_state = {0, 0};
  params.goal_state = {10, 10};
  params.grid_resolution = {0.25f, 0.25f};
  params.fixed_samples = {
    {1, 0}, {1, 1}, {0, 1}, {-1, 1},
    {-1, 0}, {-1, -1}, {0, -1}, {1, -1}
  };
  
  auto model = std::make_shared<MyCustomModel>();
  sbmpo::SBMPO planner(model);
  planner.run(params);

  sbmpo_io::print_parameters(params);
  sbmpo_io::print_results(planner.results());
  sbmpo_io::print_stats(planner.results());

  return 0;
}