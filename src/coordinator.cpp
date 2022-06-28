#include "coordinator.h"

Coordinator::Coordinator(GridEnvironment &grid_env) 
                                              : agent_num(grid_env.target_shape_num),
                                                grid_env(grid_env),
                                                agent_in_target_num(0),
                                                time_step(0), 
                                                L(1000),
                                                beta(1),
                                                omega(0.15),
                                                gamma(0.2)
{
    //set the random seed.
    srand(3);

    //initialize the agents.
    for (int i = 0; i < agent_num; i++) {
        Agent agent;
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
            agents[i].position.x = x;
            agents[i].position.y = y;
            agents[i].position.z = z;
            grid_env.grid[x][y][z].is_occupied = true;
            grid_env.grid[x][y][z].is_locked = true;
            if (grid_env.grid[x][y][z].is_target) {
                agents[i].is_in_target = true;
                agent_in_target_num++;
            }
        } else {
            i--;
        }
    }
}



//show the grid and the agents.
void Coordinator::show_grid() {
    std::cout << "----------------------" << std::endl;
    std::cout << "grid:" << std::endl;
    grid_env.show();
    std::cout << "----------------------" << std::endl;
    std::cout << "agents:" << std::endl;
    for (int i = 0; i < grid_env.grid_size_x; i++) {
        for (int j = 0; j < grid_env.grid_size_y; j++) {
            for (int k = 0; k < grid_env.grid_size_z; k++) {
                if (this->grid_env.grid[i][j][k].is_occupied) {
                    std::cout << "X" << " ";
                } else {
                    std::cout << "0" << " ";
                }
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    std::cout << "----------------------" << std::endl;
    std::cout << "agents in target shape num:" << agent_in_target_num << std::endl;
    std::cout << "ratio: %" << (double)agent_in_target_num / agent_num * 100 << std::endl;
}


bool Coordinator::is_in_grid(Position &position) {
    if (position.x < 0 || position.x >= grid_env.grid_size_x ||
        position.y < 0 || position.y >= grid_env.grid_size_y ||
        position.z < 0 || position.z >= grid_env.grid_size_z) {
        return false;
    }
    return true;
}


//calculate each agent's light field.
void Coordinator::calculate_light() {
    //L / (1+beta*distance)
    //calculate the position in target which is not occupied by an agent.
    std::vector<Position> target_empty_positions;
    for (int i = 0; i < grid_env.grid_size_x; i++) {
        for (int j = 0; j < grid_env.grid_size_y; j++) {
            for (int k = 0; k < grid_env.grid_size_z; k++) {

                if (!grid_env.grid[i][j][k].is_occupied && grid_env.grid[i][j][k].is_target) {
                    target_empty_positions.push_back(Position(i, j, k));
                }
            }
        }
    }

    //calculate the agent which is not in the target shape.
    std::vector<Position> agents_not_in_target;
    for (int i = 0; i < agent_num; i++) {
        if (!agents[i].is_in_target) {
            agents_not_in_target.push_back(agents[i].position);
        }
    }

    //for each agent in agents:
    //calculate the light field.
    //the sum of the attenuated light.

    //calculate the light field in agent's surrounding 3*3*3 grids.
    for (auto &agent : agents) {
        //empty the temp vector. 
        agent.light_field.clear();

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                for (int k = -1; k <= 1; k++) {
                    Position pos = agent.position + Position(i, j, k);
                    // judge whether the position is in the grid.
                    if (is_in_grid(pos)) {
                        double blue_light = 0;
                        double blue_distance = 0;
                        double red_light = 0;
                        double red_distance = 0;

                        for (auto &target_empty_pos: target_empty_positions) {
                            blue_distance = chebyshev_distance(pos, target_empty_pos);
                            blue_light += L / (1 + beta * blue_distance);
                        }

                        if (agent.is_in_target) {
                            for (auto &agent_not_in_target: agents_not_in_target) {
                                red_distance = chebyshev_distance(pos, agent_not_in_target);
                                red_light += L / (1 + beta * red_distance);
                            }
                        }

                        agent.light_field.push_back(LightGrid(pos, blue_light, red_light));
                    }
                    else {
                        agent.light_field.push_back(LightGrid(pos, 0, 0));
                    }
                }
            }
        }
    }

}


void Coordinator::show_light_field(Agent &agent) {
    // show the red and blue light in position's surrounding 3*3*3 grids.
    // using a 3*3*3 format.
    std::cout << "----------------------" << std::endl;
    std::cout << "blue light: " << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                std::cout << std::fixed << std::setprecision(2) << 
                          agent.light_field[i * 9 + j * 3 + k].blue_intensity << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    std::cout << "----------------------" << std::endl;
    std::cout << "red light: " << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                std::cout << std::fixed << std::setprecision(2) << 
                          agent.light_field[i * 9 + j * 3 + k].red_intensity << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}


void Coordinator::generate_priority_queues(Agent& agent) {
    //push legal light grids into the priority queues.

    //empty three queues.
    while (!agent.bd_queue.empty()) {
        agent.bd_queue.pop();
    }
    while (!agent.bd_ra_queue.empty()) {
        agent.bd_ra_queue.pop();
    }
    while (!agent.ra_queue.empty()) {
        agent.ra_queue.pop();
    }
    
    for (int i = 0; i < agent.light_field.size(); i++) {
        if (is_in_grid(agent.light_field[i].position)) {
            //Do we really need to check the positivity of the light intensity?
            if (agent.light_field[i].blue_intensity > 0) {
                agent.bd_queue.push(agent.light_field[i]);
            }
            if (agent.light_field[i].red_intensity > 0) {
                agent.bd_ra_queue.push(agent.light_field[i]);
            }
            if (agent.light_field[i].blue_intensity > 0 && agent.light_field[i].red_intensity > 0) {
                agent.ra_queue.push(agent.light_field[i]);
            }
        }
    }
}


void Coordinator::simulate() {
    while (true) {
        std::cout << "----------------------" << std::endl;
        std::cout << "time step: " << time_step << std::endl;
        if (time_step == 0) {
            show_grid();
            time_step++;
        }
        else if (time_step == 1) {
            calculate_light();
            for (auto &agent : agents) {
                 std::cout << "----------------------" << std::endl;
                 std::cout << "agent: (" << agent.position.x << ", " << agent.position.y << ", " << agent.position.z << ")" << std::endl; 
                 show_light_field(agent);
            }
            time_step++;
        }
        else {
             return;
        }
    }
}