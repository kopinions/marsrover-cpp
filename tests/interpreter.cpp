#include <gtest/gtest.h>
#include <interpreter.hpp>
#include <context.hpp>
#include "coordinate.hpp"

TEST(Interpreter, should_able_to_parse_the_placing_command) {
    std::string location = "1 2";
    interpreter it({std::make_shared<exp::placing>()});
    context ctx(location);
    auto cmds = it.interpret(ctx);
    EXPECT_EQ(cmds.size(), 1);
    std::shared_ptr<cmd::command<mars>> &ptr = cmds.at(0);
    cmd::command<mars> *pCommand = ptr.get();
    EXPECT_TRUE(dynamic_cast<cmd::placing<mars> *>(pCommand) != NULL);
}

TEST(Interpreter, should_able_to_parse_the_facing_command) {
    std::string face = "N";
    interpreter it({std::make_shared<exp::facing>()});
    context ctx(face);
    auto cmds = it.interpret(ctx);
    EXPECT_EQ(cmds.size(), 1);
    std::shared_ptr<cmd::command<mars>> &ptr = cmds.at(0);
    cmd::command<mars> *pCommand = ptr.get();
    EXPECT_TRUE(dynamic_cast<cmd::facing<mars> *>(pCommand) != NULL);
}

TEST(Interpreter, should_able_to_parse_the_placing_and_facing) {
    std::string face = "1 2 N";
    interpreter it({std::make_shared<exp::placing>(), std::make_shared<exp::facing>()});
    context ctx(face);
    auto cmds = it.interpret(ctx);
    EXPECT_EQ(cmds.size(), 2);
    EXPECT_TRUE(dynamic_cast<cmd::placing<mars>*>(cmds.at(0).get()) != NULL);
    EXPECT_TRUE(dynamic_cast<cmd::facing<mars>*>(cmds.at(1).get()) != NULL);
}


TEST(Interpreter, should_the_placing_command_make_the_mar_under_place) {
    std::string location = "1 2";
    interpreter it({std::make_shared<exp::placing>()});
    context ctx(location);
    auto cmds = it.interpret(ctx);
    EXPECT_EQ(cmds.size(), 1);
    mars mar{};
    mar.execute(cmds.at(0));
    EXPECT_EQ(mar.coord().x(), 1);
    EXPECT_EQ(mar.coord().y(), 2);
}


TEST(Interpreter, should_the_facing_command_make_the_mar_facing_direction) {
    std::string location = "N";
    interpreter it({std::make_shared<exp::facing>()});
    context ctx(location);
    auto cmds = it.interpret(ctx);
    EXPECT_EQ(cmds.size(), 1);
    mars mar{};
    mar.execute(cmds.at(0));
    EXPECT_EQ(mar.facing(), direction::N);
}

TEST(Interpreter, should_able_to_parse_rotation_command) {
    mars mar{};
    mar.execute(std::make_shared<cmd::facing<mars>>(direction::E));
    
    std::string cmd = "L";
    interpreter it({std::make_shared<exp::composite>()});
    context ctx(cmd);
    auto cmds = it.interpret(ctx);
    mar.execute(cmds.at(0));
    EXPECT_EQ(mar.facing(), direction::N);
}