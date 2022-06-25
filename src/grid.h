#ifndef GRID_H
#define GRID_H

#include <vector>
#include <random>
#include <iostream>
#include <fstream>
#include <string>


//declarement
class GridEnvironment;
class Grid;

class GridEnvironment {
public:
    // the size of the grid.
    int grid_size_x;
    int grid_size_y;
    int grid_size_z;

    // the number of cells of the target shape in grid.
    int target_shape_num;

    // the grid.
    std::vector<std::vector<std::vector<Grid>>> grid;

    // the random constructor.
    GridEnvironment(int grid_size_x, int grid_size_y, int grid_size_z, int target_shape_num);

    // the gird show function.
    void show();

    // store the grid to a file.
    void store(std::string filename);

    //load a grid from a file.
    GridEnvironment(std::string filename);
};


class Grid {
public:
    //whether the grid is part of the target shape;
    bool is_target;

    //whether the grid is currently occupied by an agent.
    bool is_currently_occupied;

    //lock.
    bool is_locked;

    Grid();

};

#endif // GRID_H