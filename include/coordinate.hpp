
#ifndef COORDINATE_HPP
#define COORDINATE_HPP


#include "direction.hpp"

class coordinate {
private:
    int _x;
    int _y;
public:
    coordinate() {}

    coordinate(int x, int y) : _x(x), _y(y) {}

    int x() { return _x; };

    int y() { return _y; };

    void forward(direction direction) {
        if (direction == direction::E) {
            _x += 1;
        } else if (direction == direction::W) {
            _x -= 1;
        } else if (direction == direction::N) {
            _y += 1;
        } else {
            _y -= 1;
        }
    };

};

#endif//COORDINATE_HPP