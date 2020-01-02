#ifndef PLACING_HPP
#define PLACING_HPP

#include "command.hpp"

template<typename T>
class placing : public command<T> {
    void applied(T &t) override {

    }
};

#endif //PLACING_HPP
