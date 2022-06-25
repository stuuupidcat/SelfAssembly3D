#ifndef COMPARE_H
#define COMPARE_H

#include "grid.h"

//compare class for priority queue.
class StageOneCompare {
public:
    bool operator() (const Grid &g1, const Grid &g2);
};


class StageTwoCompare {
public:
    bool operator() (const Grid &g1, const Grid &g2);
};


#endif // COMPARE_H