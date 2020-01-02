#ifndef COMMAND_HPP
#define COMMAND_HPP
template<typename T>
class command {
public:
    virtual ~command() = default;

    virtual void applied(T &) = 0;
};

#endif//COMMAND_HPP