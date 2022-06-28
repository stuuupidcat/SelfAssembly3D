#ifndef LIGHTFIELD_H
#define LIGHTFIELD_H

#include <vector>
#include <random>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include "position.h"

// a light grid.
class LightGrid {
public:
    Position position;
    double blue_intensity;
    double red_intensity;

    LightGrid(Position &position, double blue_intensity, double red_intensity);
    LightGrid() = default;
};

//compare class for priority queue.
class BlueDescendCompare {
public:
    bool operator() (const LightGrid lg1, const LightGrid lg2);
};


class BlueDescendRedAscendCompare {
public:
    bool operator() (const LightGrid lg1, const LightGrid lg2);
};


class RedAscendCompare {
public:
    bool operator() (const LightGrid lg1, const LightGrid lg2);
};



#endif // LIGHTFIELD_H