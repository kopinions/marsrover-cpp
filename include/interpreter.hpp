#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

#include <string>
#include "command.hpp"
#include "context.hpp"
#include "mars.hpp"
#include "expression.hpp"

class interpreter {
private:
    std::vector<std::shared_ptr<exp::expression>> _expressions;
public:
    interpreter(std::vector<std::shared_ptr<exp::expression>> exps) : _expressions(exps) {

    }

    std::vector<std::shared_ptr<cmd::command<mars>>> interpret(context ctx) {
        auto cmds = std::vector<std::shared_ptr<cmd::command<mars>>>();
        for (const auto& e: _expressions) {
            cmds.push_back(e->evaluate(ctx));
        }
        return cmds;
    }
};

#endif//INTERPRETER_HPP