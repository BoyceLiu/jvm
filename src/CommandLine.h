#ifndef SRC_COMMAND_LINE_H_
#define SRC_COMMAND_LINE_H_

#include <getopt.h>
#include <string>
#include <vector>

namespace my_jvm {

class CommandLine {
  public:
  CommandLine(const int argc, char * const argv[]);

  void parse();

  const bool help_flag() const { return help_flag_; }

  const bool version_flag() const { return version_flag_; }

  const std::string& cp_option() const { return cp_option_; }

  const std::string& class_name() const { return class_name_; }

  const std::vector<std::string>& args() const { return args_; }
 private:
  static const char *kOptString;
  const static struct option kLongOpts[];
  int argc;
  char * const *argv;
  bool help_flag_;
  bool version_flag_;
  std::string cp_option_;
  std::string class_name_;
  std::vector<std::string> args_;
};

} // namespace my_jvm

#endif // SRC_COMMAND_LINE_H_
