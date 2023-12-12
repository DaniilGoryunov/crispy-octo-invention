#pragma once
#include <iostream>
#include "coord.hpp"

class Figure {
public:
    Figure();
    ~Figure();
    virtual Coord get_center() const = 0;
    virtual operator double() const = 0;
};
