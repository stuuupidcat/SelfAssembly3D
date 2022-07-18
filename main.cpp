#include "src/grid.h"
#include "src/agent.h"
#include "src/coordinator.h"
#include "src/lightfield.h"
#include "src/position.h"
#include "src/shape.h"

#include <sys/stat.h>
#include <sys/types.h>



int main() {

    std::vector<std::string> files = {"convex", "concave", "onehole", "multihole"};
    std::vector<std::string> inputs;

    for (auto file : files) {
        for (int i = 1; i <= 3; ++i)
            for (int j = 7; j <= 7; j = j+2)
                inputs.push_back(file + std::to_string(i) + "_layer_" + std::to_string(j) + ".txt");
    }

    double omega = 0.2;
    double alpha = 1000000;

    std::string outputdir = "../output_omega_" + std::to_string(omega).substr(0, 5) + "_alpha_" + std::to_string(alpha).substr(0, 5);

    //make a directory which is named as the outputdir
    mkdir(outputdir.c_str());

    for (auto input : inputs) {
        //std::cout << input << std::endl;
        GridEnvironment grid_env("D:\\Workspace\\workspace_python\\img\\" + input);
        Coordinator coordinator(grid_env);

        coordinator.omega = omega;
        coordinator.alpha = alpha;
        
        
        std::string output = input;
        std::ofstream outfile(outputdir + "/" + output);
        std::streambuf* coutbuf = std::cout.rdbuf();
        std::cout.rdbuf(outfile.rdbuf());

        coordinator.simulate();    
    }
    
}