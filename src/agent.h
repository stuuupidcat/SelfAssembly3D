#ifndef AGENT_H
#define AGENT_H

#include "grid.h"
#include "compare.h"

#include <vector>
#include <random>
#include <iostream>
#include <fstream>
#include <string>
#include <queue>


class Agent {
public:
    //the coordinate of the agent.
    int cur_position[3];

    //whether the agent is in the target shape.
    bool is_in_target;

    //two priority queues.
    std::priority_queue<Grid, std::vector<Grid>, StageOneCompare> stage_one_queue;
    std::priority_queue<Grid, std::vector<Grid>, StageTwoCompare> stage_two_queue;

    //move the agent to a new position.
    void move_to(int nx, int ny, int nz);

    //the constructor.
    Agent();
};

#endif