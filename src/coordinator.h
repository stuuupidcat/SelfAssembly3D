#ifndef COORDINATOR_H
#define COORDINATOR_H

#include "grid.h"
#include "agent.h"
#include "time.h"
#include "lightfield.h"
#include "position.h"

#include <vector>
#include <random>
#include <iostream>
#include <fstream>
#include <string>
#include <queue>

#include <thread>
#include <mutex>
#include <atomic>



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
    Coordinator(GridEnvironment &grid_env);

    //show the grid state and the agent position.
    void show_grid();

    //judge whether a (x, y, z) in the grid.
    bool is_in_grid(Position &position);

    //calculate the light intensity, p.25 of the paper.
    //"At any time t, each agent in O_t is a source of red light,
    // and each grid in U_t is a source of blue light. "
    double L, beta, omega, W, gamma, alpha;
    bool flag;

    //calculate the portion of the occupied grid in the target shape.
    void calculate_W();

    void calculate_light();

    //show the light field.
    void show_light_field(Agent &agent);

    //push legal light grids into the priority queues.
    void generate_priority_queues(Agent &agent);

    //choose next position in multi-thread, delta:the result of current occupancy - (1-omega)
    template<typename T>
    void choose_next_position(Agent &agent, T &queue, double delta);

    //move to next position or stay.
    void move_to_next_position(Agent &agent);

    //change state of grid.
    void change_grid_state();


    //simulate.
    void simulate();
};


#endif // COORDINATOR_H