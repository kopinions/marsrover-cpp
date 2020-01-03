
#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include "command.hpp"
#include "coordinate.hpp"
#include "direction.hpp"

namespace exp {
    class expression {
    public:
        virtual ~expression() = default;

        virtual std::shared_ptr<cmd::command<mars>> evaluate(context &ctx) = 0;
    };

    class facing : public expression {
    private:
        inline static std::map<std::string, direction> mapping = {
                {"E", direction::E},
                {"S", direction::S},
                {"W", direction::W},
                {"N", direction::N}
        };
    public:
        std::shared_ptr<cmd::command<mars>> evaluate(context &ctx) override {
            const std::string direction = ctx.next();
            return std::make_shared<cmd::facing<mars>>(mapping[direction]);
        }
    };

    class placing : public expression {
    public:
        std::shared_ptr<cmd::command<mars>> evaluate(context &ctx) override {
            const std::string x = ctx.next();
            const std::string y = ctx.next();
            return std::make_shared<cmd::placing<mars>>(std::stoi(x), std::stoi(y));
        }
    };

    class composite : public expression {
    private:
        inline static std::map<char, direction::turn> towards_mapping = {
                {'R', direction::turn::CW},
                {'L', direction::turn::CCW},
        };
    public:
        std::shared_ptr<cmd::command<mars>> evaluate(context &ctx) override {
            const std::string x = ctx.next();
            std::vector<std::shared_ptr<cmd::command<mars>>> cmds;
            for (auto c:x) {
                if (c == 'R' || c == 'L') {
                    cmds.emplace_back(std::make_shared<cmd::rotate<mars>>(towards_mapping[c]));
                }
                if (c == 'M') {
                    cmds.emplace_back(std::make_shared<cmd::move<mars>>());
                }
            }
            return std::make_shared<cmd::composite<mars>>(cmds);
        }
    };
}

#endif //EXPRESSION_HPP
