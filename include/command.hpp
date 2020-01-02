#ifndef COMMAND_HPP
#define COMMAND_HPP
namespace cmd {
    template<typename T>
    class command {
    public:
        virtual ~command() = default;

        virtual void applied(T &) = 0;
    };


    template<typename T>
    class facing : public command<T> {
    public:
        void applied(T &t) override {

        }
    };


    template<typename T>
    class placing : public command<T> {
        void applied(T &t) override {

        }
    };

}


#endif//COMMAND_HPP