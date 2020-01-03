
#ifndef COORDINATE_HPP
#define COORDINATE_HPP

class coordinate {
private:
    int _x;
    int _y;
public:
    coordinate(int x, int y) : _x(x), _y(y) {}

    int x() { return _x; };

    int y() { return _y; };
    enum class direction {
        E, S, W, N
    };
};

#endif//COORDINATE_HPP