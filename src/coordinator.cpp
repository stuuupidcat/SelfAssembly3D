#include "coordinator.h"

Coordinator::Coordinator(int agent_num, GridEnvironment &grid_env) : agent_num(agent_num),
                                                                     grid_env(grid_env),
                                                                     time_step(0) 
{
    //initialize the agents.
    for (int i = 0; i < agent_num; i++) {
        Agent agent(i);
        agents.push_back(agent);
    }

    //randomly put the agents in the grid.
    //and check if the agent is in the target shape.

    for (int i = 0; i < agent_num; i++) {
        int x = rand() % grid_env.grid_size_x;
        int y = rand() % grid_env.grid_size_y;
        int z = rand() % grid_env.grid_size_z;
        //find an empty position.
        if (!grid_env.grid[x][y][z].is_occupied) {
            agents[i].move_to(x, y, z);

            grid_env.grid[x][y][z].is_occupied = true;
            grid_env.grid[x][y][z].occupied_by = &agents[i];

            if (grid_env.grid[x][y][z].is_target) {
                agents[i].is_in_target = true;
            }
        } else {
            i--;
        }
    }
}



//show the grid and the agents.
void Coordinator::show() {
    std::cout << "time step: " << time_step << std::endl;
    std::cout << "grid:" << std::endl;
    grid_env.show();

    std::cout << "agents:" << std::endl;
    for (int i = 0; i < agent_num; i++) {
        std::cout << "agent " << i << ": " << agents[i].cur_position[0] << " " << agents[i].cur_position[1] << " " << agents[i].cur_position[2] << std::endl;
    }

}