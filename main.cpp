#include "src/grid.h"
#include "src/agent.h"
#include "src/coordinator.h"
#include "src/lightfield.h"
#include "src/position.h"



int main() {
    //GridEnvironment grid_env("data/grid.txt");
    GridEnvironment grid_env(16,16,16,200);
    Coordinator coordinator(grid_env);     
    coordinator.simulate();    
}