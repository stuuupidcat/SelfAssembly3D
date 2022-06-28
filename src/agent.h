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
    //the coordinate of the agent.
    Position position;
    std::vector<Position> path;

    //whether the agent is in the target shape.
    bool is_in_target;

    //temp light_field;
    std::vector<LightGrid> light_field;

    //three priority queues.
    std::priority_queue<LightGrid, std::vector<LightGrid>, BlueDescendCompare> bd_queue;
    std::priority_queue<LightGrid, std::vector<LightGrid>, BlueDescendRedAscendCompare> bd_ra_queue;
    std::priority_queue<LightGrid, std::vector<LightGrid>, RedAscendCompare> ra_queue;

    //move the agent to a new position.
    void move_to(int nx, int ny, int nz);

    //the constructor.
    Agent();
};

#endif