#include "CommandLine.h"
#include <gtest/gtest.h>

TEST(CommandLineTest, HandleNormalInput1) {
  int argc = 6;
  char *argv[] = {
    "my_jvm",
    "--cp",
    "someClassPath",
    "className",
    "arg1",
    "arg2"
  };
  my_jvm::CommandLine commandLine(argc, argv);
  commandLine.parse();
  EXPECT_STREQ("someClassPath", commandLine.cp_option().c_str());
  EXPECT_STREQ("className", commandLine.class_name().c_str());
  ASSERT_EQ(2, commandLine.args().size());
  EXPECT_STREQ("arg1", commandLine.args()[0].c_str());
  EXPECT_STREQ("arg2", commandLine.args()[1].c_str());
}

TEST(CommandLineTest, HandleNormalInput2) {
  int argc = 6;
  char *argv[] = {
    "my_jvm",
    "--classpath",
    "someClassPath",
    "className",
    "arg1",
    "arg2"
  };
  my_jvm::CommandLine commandLine(argc, argv);
  commandLine.parse();
  EXPECT_STREQ("someClassPath", commandLine.cp_option().c_str());
  EXPECT_STREQ("className", commandLine.class_name().c_str());
  ASSERT_EQ(2, commandLine.args().size());
  EXPECT_STREQ("arg1", commandLine.args()[0].c_str());
  EXPECT_STREQ("arg2", commandLine.args()[1].c_str());
}

TEST(CommandLineTest, HandleHelpInput1) {
  int argc = 2;
  char *argv[] = {
    "my_jvm",
    "--help"
  };
  my_jvm::CommandLine commandLine(argc, argv);
  commandLine.parse();
  EXPECT_TRUE(commandLine.help_flag());
}

TEST(CommandLineTest, HandleHelpInput2) {
  int argc = 2;
  char *argv[] = {
    "my_jvm",
    "-h"
  };
  my_jvm::CommandLine commandLine(argc, argv);
  commandLine.parse();
  EXPECT_TRUE(commandLine.help_flag());
}

TEST(CommandLineTest, HandleVersionInput1) {
  int argc = 2;
  char *argv[] = {
    "my_jvm",
    "--version"
  };
  my_jvm::CommandLine commandLine(argc, argv);
  commandLine.parse();
  EXPECT_TRUE(commandLine.version_flag());
}

TEST(CommandLineTest, HandleVersionInput2) {
  int argc = 2;
  char *argv[] = {
    "my_jvm",
    "-v"
  };
  my_jvm::CommandLine commandLine(argc, argv);
  commandLine.parse();
  EXPECT_TRUE(commandLine.version_flag());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
