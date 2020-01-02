#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

#include <string>
#include "command.hpp"
#include "context.hpp"
#include "mars.hpp"
#include "placing.hpp"

class interpreter {
private:
public:
    std::vector<std::shared_ptr<command<mars>>> interpret(context ctx) {
        auto cmds = std::vector<std::shared_ptr<command<mars>>>();
        cmds.push_back(std::make_shared<placing<mars>>());
        return cmds;
    }
};

#endif//INTERPRETER_HPP