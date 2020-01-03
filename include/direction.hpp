#ifndef DIRECTION_HPP
#define DIRECTION_HPP

class direction {
private:
    enum class towards {
        EAST = 1, SOUTH = 2, WEST = 3, NORTH = 4
    };
    towards _towards;

    direction(towards t) : _towards(t) {
    }

public:
    direction() {}

    enum class turn {
        CCW, CW
    };

    void on(turn t) {
        if (t == turn::CW) {
            _towards = static_cast<towards >((static_cast<int>(_towards) + 1) % 4);
        } else {
            int minus = static_cast<int> (_towards) - 1;
            _towards = static_cast<towards > (minus == 0 ? 4 : minus);
        }
    }

    inline bool operator==(const direction &rhs) const {
        return _towards == rhs._towards;
    };


public:
    static direction E;
    static direction S;
    static direction W;
    static direction N;
};

direction direction::E = direction(towards::EAST);
direction direction::S = direction(towards::SOUTH);
direction direction::W = direction(towards::WEST);
direction direction::N = direction(towards::NORTH);
#endif //DIRECTION_HPP
