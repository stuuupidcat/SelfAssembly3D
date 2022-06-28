#include "grid.h"
// class GridEnvironment

// the random constructor.
GridEnvironment::GridEnvironment(int grid_size_x, int grid_size_y, int grid_size_z, int target_shape_num) {
    srand(5);
    //initialize the grid.
    this->grid_size_x = grid_size_x;
    this->grid_size_y = grid_size_y;
    this->grid_size_z = grid_size_z;
    this->target_shape_num = target_shape_num;
    this->grid.resize(grid_size_x);
    for (int i = 0; i < grid_size_x; i++) {
        this->grid[i].resize(grid_size_y);
        for (int j = 0; j < grid_size_y; j++) {
            this->grid[i][j].resize(grid_size_z);
        }
    }

    //fill the grid randomly with 1, totally target_shape_num of 1.
    for (int i = 0; i < target_shape_num; i++) {
        int x = rand() % grid_size_x;
        int y = rand() % grid_size_y;
        int z = rand() % grid_size_z;
        if (this->grid[x][y][z].is_target == false) {
            this->grid[x][y][z].is_target = true;
        } else {
            i--;
        }
    }
}


// the grid show function.
void GridEnvironment::show() {
    for (int i = 0; i < grid_size_x; i++) {
        for (int j = 0; j < grid_size_y; j++) {
            for (int k = 0; k < grid_size_z; k++) {
                if (this->grid[i][j][k].is_target) {
                    std::cout << "1" << " ";
                } else {
                    std::cout << "0" << " ";
                }
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}


// store the grid to a file.
void GridEnvironment::store(std::string filename) {
    std::ofstream outfile;
    outfile.open(filename);
    outfile << grid_size_x << " " << grid_size_y << " " << grid_size_z << " " << target_shape_num << std::endl;
    for (int i = 0; i < grid_size_x; i++) {
        for (int j = 0; j < grid_size_y; j++) {
            for (int k = 0; k < grid_size_z; k++) {
                if (this->grid[i][j][k].is_target) {
                    outfile << "1" << " ";
                } else {
                    outfile << "0" << " ";
                }
            }
            outfile << std::endl;
        }
        outfile << std::endl;
    }
    outfile.close();
}


// load a grid from a file.
GridEnvironment::GridEnvironment(std::string filename) {
    std::ifstream infile;
    infile.open(filename);
    if (!infile.is_open()) {
        std::cout << "Error: cannot open file " << filename << std::endl;
        exit(1);
    }

    infile >> grid_size_x >> grid_size_y >> grid_size_z >> target_shape_num;
    grid.resize(grid_size_x);
    for (int i = 0; i < grid_size_x; i++) {
        grid[i].resize(grid_size_y);
        for (int j = 0; j < grid_size_y; j++) {
            grid[i][j].resize(grid_size_z);
        }
    }

    for (int i = 0; i < grid_size_x; i++) {
        for (int j = 0; j < grid_size_y; j++) {
            for (int k = 0; k < grid_size_z; k++) {
                infile >> grid[i][j][k].is_target;
            }
        }
    }

    infile.close();   
}


//end of class GridEnvironment


// class Grid
Grid::Grid() {
    is_target = false;
    is_occupied = false;
    is_locked = false;
};

Grid::Grid(Grid&& other) {
    is_target = other.is_target;
    is_occupied = other.is_occupied;
    is_locked = other.is_locked;
};