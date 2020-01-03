#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "coordinate.hpp"

namespace cmd {
    template<typename T>
    class command {
    public:
        virtual ~command() = default;

        virtual void applied(T &) = 0;
    };


    template<typename T>
    class facing : public command<T> {
    private:
        coordinate::direction _direction;
    public:
        facing(coordinate::direction direction) :_direction(direction) {

        }
        void applied(T &t) override {
            t.facing(_direction);
        }
    };


    template<typename T>
    class placing : public command<T> {
    private:
        int _x, _y;
    public:
        placing(int x, int y) : _x(x), _y(y) {

        }

        void applied(T &t) override {
            t.locate(coordinate(_x, _y));
        }
    };

}


#endif//COMMAND_HPP