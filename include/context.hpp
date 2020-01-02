#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include <string>
#include <range/v3/view.hpp>

class context {
private:
    std::vector<std::string> _tokens;
    std::vector<std::string>::iterator iter;
public:
    context(std::string input)  {
        _tokens = input | ranges::views::split(' ') | ranges::to<std::vector<std::string>>();
         iter = _tokens.begin();
    }

    std::string next() {
        std::string &res = *iter;
        iter++;
        return res;
    }
};

#endif//CONTEXT_HPP
