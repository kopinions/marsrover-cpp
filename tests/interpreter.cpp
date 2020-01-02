#include <gtest/gtest.h>
#include <interpreter.hpp>
#include <context.hpp>

TEST(Interpreter, should_able_to_parse_the_placing_command) {
    std::string location = "1 2";
    interpreter it({std::make_shared<exp::placing>()});
    context ctx(location);
    auto cmds = it.interpret(ctx);
    EXPECT_EQ(cmds.size(), 1);
    std::shared_ptr<cmd::command<mars>> &ptr = cmds.at(0);
    cmd::command<mars> *pCommand = ptr.get();
    EXPECT_TRUE(dynamic_cast<cmd::placing<mars>*>(pCommand) != NULL);
}

TEST(Interpreter, should_able_to_parse_the_facing_command) {
    std::string face = "N";
    interpreter it({std::make_shared<exp::facing>()});
    context ctx(face);
    auto cmds = it.interpret(ctx);
    EXPECT_EQ(cmds.size(), 1);
    std::shared_ptr<cmd::command<mars>> &ptr = cmds.at(0);
    cmd::command<mars> *pCommand = ptr.get();
    EXPECT_TRUE(dynamic_cast<cmd::facing<mars>*>(pCommand) != NULL);
}