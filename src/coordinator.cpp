#include "coordinator.h"

Coordinator::Coordinator(GridEnvironment &grid_env) 
                                              : agent_num(grid_env.target_shape_num),
                                                grid_env(grid_env),
                                                alpha(1000000),
                                                time_step(0), 
                                                L(1000),
                                                beta(1),
                                                omega(0.15),
                                                gamma(0.2)
{
    //set the random seed.
    srand(time(NULL));
    //srand(17);

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
            agents[i].position = Position(x, y, z);
            agents[i].id = i;
            agents[i].path.push_back(agents[i].position);
            grid_env.grid[x][y][z].is_occupied = true;
            grid_env.grid[x][y][z].is_locked = true;
            if (grid_env.grid[x][y][z].is_target) {
                agents[i].is_in_target = true;
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
}


bool Coordinator::is_in_grid(Position &position) {
    if (position.x < 0 || position.x >= grid_env.grid_size_x ||
        position.y < 0 || position.y >= grid_env.grid_size_y ||
        position.z < 0 || position.z >= grid_env.grid_size_z) {
        return false;
    }
    return true;
}

 //calculate the portion of the occupied grid in the target shape.
void Coordinator::calculate_W() {
    W = 0;
    for (int i = 0; i < grid_env.grid_size_x; i++) {
        for (int j = 0; j < grid_env.grid_size_y; j++) {
            for (int k = 0; k < grid_env.grid_size_z; k++) {
                if (grid_env.grid[i][j][k].is_target) {
                    if (grid_env.grid[i][j][k].is_occupied) {
                        W = W + 1;
                    }
                }
            }
        }
    }
    W = W / (double)grid_env.target_shape_num;
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

                        if (agent.is_in_target) { //
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
                 std::cout << "agent: (" << agent.position.x << ", " << agent.position.y << ", " << agent.position.z << ")" << std::endl; 
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

template <typename T>
void Coordinator::choose_next_position(Agent &agent, T& q, double delta) {
    //this function only change the agent's next_position and the grid's is_locked.
    //initialize the light grid
    auto candidate_pos = Position(-1, -1, -1);
    agent.next_position = candidate_pos;    //initialize the next_position to -1,-1,-1.

    if (q.empty()) {
        agent.next_position = agent.position;
        return;
    }
    else {
        while(!q.empty()) {
            auto top = q.top();
            q.pop();
            Grid &top_grid = grid_env.grid[top.position.x][top.position.y][top.position.z];
            top_grid.lock.lock();

            if (top_grid.is_locked) {
                top_grid.lock.unlock();
                continue;
            }
            else {
                if (!top_grid.is_target) {
                    //delta: the result of {current occupancy - (1-omega)}
                    //when delta < 0, can leave the target;
                    //when delta > 0 (delta max: omega), 
                    //the agent can leave the target at a rate of (omega - delta)/alpha.
                    //e.g. current occupancy = 0.89, omega = 0.15, delta = 0.89 - (1-0.15) = 0.04
                    //the agent can leave the target at a rate of (0.15 - 0.04)/alpha = 0.11/alpha

                    double dice = (rand() % 1001)/1000.0;
                    double can_leave_target_rate = (omega - delta)/alpha;
                    if (delta < 0) {
                        //try to occupy the grid.
                    }
                    else if (dice > can_leave_target_rate) {
                        top_grid.lock.unlock();
                        continue;
                    }
                    else {
                        //try to occupy the grid.
                    }
                }

                //change the state of the grid.
                //when moving, you need to handle other states of the grid.
                top_grid.is_locked = true;
                top_grid.lock.unlock();

                //if we have a candidate position, we need to change the state of the grid.
                if (candidate_pos.x != -1) {
                    Grid &candidate_grid = grid_env.grid[candidate_pos.x][candidate_pos.y][candidate_pos.z];
                    candidate_grid.lock.lock();
                    candidate_grid.is_locked = false;
                    candidate_grid.lock.unlock();
                }

                //generate a random number between [0, 1], to compare with the gamma.;
                double p = (rand() % 11)/10.0;
                if (p < gamma) {
                    candidate_pos = top.position;
                    continue;
                }
                else {
                    agent.next_position = top.position;
                    Grid &left_grid = grid_env.grid[agent.position.x][agent.position.y][agent.position.z];
                    left_grid.lock.lock();
                    left_grid.is_locked = false;
                    left_grid.lock.unlock();
                    return;
                }
            }
        }
        //there is no more candidate position.
        if (candidate_pos.x != -1) {
            agent.next_position = candidate_pos;
        }
        else {
            agent.next_position = agent.position;
        }
    }

}

void Coordinator::move_to_next_position(Agent &agent) {
    //move the agent to the next_position.
    //if the next_position is the same as the current position, do nothing.
    if (agent.next_position == agent.position) {
        agent.actions.push_back(0);
        agent.path.push_back(agent.position);
        return;
    }
    else {

        agent.actions.push_back(1);
        agent.path.push_back(agent.position);
        if (grid_env.grid[agent.position.x][agent.position.y][agent.position.z].is_target) {
            agent.is_in_target = true;
        }
        else {
            agent.is_in_target = false;
        }

        agent.position = agent.next_position;
        return;
    }
}


void Coordinator::change_grid_state() {
    //change all grid's is_occupied to false.
    for (int i = 0; i < grid_env.grid.size(); i++) {
        for (int j = 0; j < grid_env.grid[i].size(); j++) {
            for (int k = 0; k < grid_env.grid[i][j].size(); k++) {
                grid_env.grid[i][j][k].is_occupied = false;
            }
        }
    }

    //change the grid's is_occupied to true.
    for (int i = 0; i < agents.size(); i++) {
        Grid &grid = grid_env.grid[agents[i].position.x][agents[i].position.y][agents[i].position.z];
        grid.is_occupied = true;
    }
}


void Coordinator::simulate() {
    double max_W = 0;
    int max_W_index = 0;
    //calculate the mean running time of each iteration.
    double mean_running_time = 0;
    while (true) {
        double start_time = clock();
        //std::cout << "----------------------" << std::endl;
        //std::cout << "time step: " << time_step ; // << std::endl;
        //std::cout << "----------------------" << std::endl;
        calculate_W();
        //std::cout << " W: %" << std::fixed << std::setprecision(3) << W * 100 << std::endl;
        if (W > max_W) {
            max_W = W;
            max_W_index = time_step;
            //show_grid();
        }

        
        if (fabs(W - 1) < 0.000001) {
            std::cout << "Finish!" << std::endl;
            show_grid();
            break;
        }

        if (time_step > 100) {
            std::cout << "Agents number: " << agents.size() << std::endl;
            //show max_w
            std::cout << "max_W: %" << std::fixed << std::setprecision(3) << max_W * 100 << " at time step: " << max_W_index << std::endl;
            //show mean_running_time
            std::cout << "mean_running_time: " << std::fixed << std::setprecision(3) << mean_running_time / time_step << std::endl;
            std::cout << "mean_agent_running_time: " << std::fixed << std::setprecision(3) << mean_running_time / time_step / agents.size() << std::endl;
            std::cout << "Time out!" << std::endl;
            show_grid();
            break;
        }

        calculate_light();
        //for (auto &agent : agents) {     
        //    show_light_field(agent);
        //}
        //use multi-thread to generate the priority queues for every agent.
        std::vector<std::thread> threads;
        for (auto &agent : agents) {
            threads.push_back(std::thread(&Coordinator::generate_priority_queues, this, std::ref(agent)));
        }
        for (auto &thread : threads) {
            thread.join();
        }

        //use multi-thread to choose the next position for every agent.
        threads.clear();
        for (auto &agent : agents) {
            double delta = W - (1-omega);
            if (!agent.is_in_target) {
                //choose the bd_queue
                threads.push_back(std::thread(&Coordinator::choose_next_position<std::priority_queue<LightGrid, std::vector<LightGrid>, BlueDescendCompare>>, 
                                                 this, std::ref(agent), std::ref(agent.bd_queue), delta));
            }
            else {
                if (delta < 0) {
                    //choose the bd_ra_queue
                    threads.push_back(std::thread(&Coordinator::choose_next_position<std::priority_queue<LightGrid, std::vector<LightGrid>, BlueDescendRedAscendCompare>>, 
                                             this, std::ref(agent), std::ref(agent.bd_ra_queue), delta));
                }
                else {
                    threads.push_back(std::thread(&Coordinator::choose_next_position<std::priority_queue<LightGrid, std::vector<LightGrid>, RedAscendCompare>>, 
                                             this, std::ref(agent), std::ref(agent.ra_queue), delta));
                }
            }
        }

        for (auto &thread : threads) {
            thread.join();
        }

        //use multi-thread to move the agent to the next position.
        threads.clear();
        for (auto &agent : agents) {
            threads.push_back(std::thread(&Coordinator::move_to_next_position, this, std::ref(agent)));
        }
        for (auto &thread : threads) {
            thread.join();
        }

        //change the grid's state.
        change_grid_state();

        //output agent's path.
        //for (auto &agent : agents) {
        //    agent.output_action();
        //}

        //update the time step.
        time_step++;
        double end_time = clock();
        mean_running_time += (end_time - start_time);
    }
}