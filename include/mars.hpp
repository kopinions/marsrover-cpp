#ifndef MARS_HPP
#define MARS_HPP

#include "coordinate.hpp"

class mars {
private:
    coordinate _coordinate = coordinate(0,0);
    direction _direction{};
public:
    void execute(const std::shared_ptr<cmd::command<mars>> &cmd) {
        cmd->applied(*this);
    }

    coordinate coord() {
        return _coordinate;
    }

    void locate(class coordinate c)  {
        _coordinate = c;
    };

    void facing(direction  direction)  {
        _direction = direction;
    };

    void rotate(direction::turn t) {
        _direction.on(t);
    }

    mars() {

    }

    const direction facing() {
        return _direction;
    }
};

#endif//MARS_HPP
