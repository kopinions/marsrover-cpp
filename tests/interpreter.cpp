#include <gtest/gtest.h>
#include <interpreter.hpp>
#include <context.hpp>

TEST(Interpreter, should_able_to_parse_the_placing_command) {
    std::string location = "1 2";
    interpreter it;
    context ctx(location);
    auto cmds = it.interpret(ctx);
    EXPECT_EQ(cmds.size(), 1);
    std::shared_ptr<command<mars>> &ptr = cmds.at(0);
    command<mars> *pCommand = ptr.get();
    EXPECT_TRUE(dynamic_cast<placing<mars>*>(pCommand) != NULL);
}
