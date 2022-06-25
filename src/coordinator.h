#ifndef COORDINATOR_H
#define COORDINATOR_H

#include "grid.h"
#include "compare.h"
#include "agent.h"

#include <vector>
#include <random>
#include <iostream>
#include <fstream>
#include <string>
#include <queue>


class Coordinator {
public:
    //the agent number.
    int agent_num;
    
    //contains a grid environment.
    GridEnvironment &grid_env;

    //a bunch of agents.
    std::vector<Agent> agents;

    //discrete time.
    int time_step;

    //the constructor.
    Coordinator(int agent_num, GridEnvironment &grid_env);

    //show the grid state and the agent position.
    void show();

    //store the grid state and the agent position to a file.
    void store(std::string filename);
};


#endif // COORDINATOR_H