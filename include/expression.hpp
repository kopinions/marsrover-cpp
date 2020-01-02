
#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include "command.hpp"

namespace exp {
    class expression {
    public:
        virtual ~expression() = default;
        virtual std::shared_ptr<cmd::command<mars>> evaluate(context ctx) = 0;
    };

    class facing : public expression {
    public:
        std::shared_ptr<cmd::command<mars>> evaluate(context ctx) override {
            return std::make_shared<cmd::facing<mars>>();
        }
    };

    class placing: public  expression {
    public:
        std::shared_ptr<cmd::command<mars>> evaluate(context ctx) override {
            return std::make_shared<cmd::placing<mars>>();

        }
    };
}

#endif //EXPRESSION_HPP
