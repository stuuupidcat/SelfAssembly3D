#include "lightfield.h"

LightGrid::LightGrid(Position position, double blue_intensity, double red_intensity) {
    this->position = Position(position.x, position.y, position.z);
    this->blue_intensity = blue_intensity;
    this->red_intensity = red_intensity;
}

bool BlueDescendCompare::operator() (const LightGrid& lg1, const LightGrid& lg2) const{
    return lg1.blue_intensity < lg2.blue_intensity;
}


bool BlueDescendRedAscendCompare::operator() (const LightGrid& lg1, const LightGrid& lg2) const{
    if (lg1.blue_intensity < lg2.blue_intensity) {
        return true;
    } else if (lg1.blue_intensity == lg2.blue_intensity) {
        return lg1.red_intensity > lg2.red_intensity;
    } else {
        return false;
    }
}


bool RedAscendCompare::operator() (const LightGrid& lg1, const LightGrid& lg2) const{
    return lg1.red_intensity > lg2.red_intensity;
}