#ifndef POSITION_H
#define POSITION_H


#include <cmath>

class Position {
public:
    int x;
    int y;
    int z;
    Position(int x, int y, int z);
    Position() = default;

    Position operator+ (const Position &p) const;
};


double chebyshev_distance(Position &p1, Position &p2);

#endif // POSITION_H