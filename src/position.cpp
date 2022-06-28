#include "position.h"

Position::Position(int x, int y, int z):
    x(x),
    y(y),
    z(z) {}


Position Position::operator+ (const Position &p) const {
    return Position(x + p.x, y + p.y, z + p.z);
}

bool Position::operator== (const Position &p) const {
    return x == p.x && y == p.y && z == p.z;
}

double chebyshev_distance(Position &p1, Position &p2) {
    double dx = abs(p1.x - p2.x);
    double dy = abs(p1.y - p2.y);  
    double dz = abs(p1.z - p2.z);
    return fmax(dx, fmax(dy, dz));
}



