#include "src/grid.h"
#include "src/agent.h"
#include "src/coordinator.h"
#include "src/lightfield.h"
#include "src/position.h"
#include "src/shape.h"


void do_something() {
    for (int i = 3; i <= 7; i += 2) {
        generate_x_cube(9, i);
    }
    
}

int main(int argc, char* argv[]) {
    std::string input = argv[1];
    std::string output = argv[2];
    //do_something();
    GridEnvironment grid_env(input);
    //redirect stdout to a file.
    std::ofstream outfile(output);
    std::streambuf* coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(outfile.rdbuf());
    //GridEnvironment grid_env(16,16,16,200);
    Coordinator coordinator(grid_env);     
    coordinator.simulate();    
}