#ifndef AGENT_H
#define AGENT_H

#include "lightfield.h"

#include <vector>
#include <random>
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <cmath>

#include "lightfield.h"

class Agent {
public:
    int id;
    
    //the coordinate of the agent.
    Position position, next_position;

    std::vector<Position> path;
    //0 for stay and 1 for move.
    std::vector<bool> actions;

    //whether the agent is in the target shape.
    bool is_in_target;

    //temp light_field;
    std::vector<LightGrid> light_field;

    //three priority queues.
    std::priority_queue<LightGrid, std::vector<LightGrid>, BlueDescendCompare> bd_queue;
    std::priority_queue<LightGrid, std::vector<LightGrid>, BlueDescendRedAscendCompare> bd_ra_queue;
    std::priority_queue<LightGrid, std::vector<LightGrid>, RedAscendCompare> ra_queue;

    //the constructor.
    Agent();

    //output last action
    void output_action();
};

#endif