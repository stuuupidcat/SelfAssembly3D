#include "agent.h"


//the constructor.
Agent::Agent() {
    cur_position[0] = 0;
    cur_position[1] = 0;
    cur_position[2] = 0;
    is_in_target = false;
}


//move the agent to a new position.
void Agent::move_to(int nx, int ny, int nz) {
    cur_position[0] = nx;
    cur_position[1] = ny;
    cur_position[2] = nz;
}