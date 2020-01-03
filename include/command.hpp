#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "coordinate.hpp"
#include "direction.hpp"

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
        direction _direction;
    public:
        explicit facing(direction direction) : _direction(direction) {

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

    template<typename T>
    class composite : public command<T> {
    private:
        std::vector<std::shared_ptr<command<T>>> _commands;
    public:
        composite(std::vector<std::shared_ptr<command<T>>> commands) : _commands(commands) {

        }

        void applied(T &t) override {
            for (auto cmd :  _commands) {
                cmd->applied(t);
            }
        }
    };

    template<typename T>
    class rotate : public command<T> {
    private:
        direction::turn _towards;
    public:
        rotate(direction::turn towards) : _towards(towards) {}

        void applied(T &t) override {
            t.rotate(_towards);
        }
    };

    template<typename T>
    class move: public command<T> {
    private:
    public:
        move() {};

        void applied(T &t) override {
            t.move();
        }
    };
}


#endif//COMMAND_HPP