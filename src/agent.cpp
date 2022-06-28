#include "agent.h"

//the constructor.
Agent::Agent() {
    position = Position(0, 0, 0);
    is_in_target = false;
}


//move the agent to a new position.
void Agent::move_to(int nx, int ny, int nz) {
    if (nx == position.x && ny == position.y && nz == position.z) {
        return;
    }
    else {
        path.push_back(position);
        position.x = nx;
        position.y = ny;
        position.z = nz;
    }
}
