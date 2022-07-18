#include "agent.h"

//the constructor.
Agent::Agent() {
    id = 0;
    position = Position(0, 0, 0);
    is_in_target = false;
}

void Agent::output_action() {
    std::cout << "Agent " << id << ": ";
    if (actions[actions.size() - 1] == 0) {
        std::cout << "stay at " << 
            "(" << position.x << ", " << position.y << ", " << position.z << ")" << std::endl;
    } else {
        auto last_position = path[path.size() - 1];
        std::cout << "move from" << 
            "(" << last_position.x << ", " << last_position.y << ", " << last_position.z << ")" <<
            " to " <<
            "(" << position.x << ", " << position.y << ", " << position.z << ")" << std::endl;
    }
    
}

