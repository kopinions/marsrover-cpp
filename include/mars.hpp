#ifndef MARS_HPP
#define MARS_HPP

#include "coordinate.hpp"

class mars {
private:
    coordinate _coordinate = coordinate(0,0);
public:
    void execute(std::shared_ptr<cmd::command<mars>> &cmd) {
        cmd->applied(*this);
    }

    coordinate coord() {
        return _coordinate;
    }

    void locate(class coordinate c)  {
        _coordinate = c;
    };

    mars() {

    }
};

#endif//MARS_HPP
