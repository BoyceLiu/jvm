#include "CommandLine.h"

namespace my_jvm {

const char* CommandLine::kOptString = "hv";
const struct option CommandLine::kLongOpts[] = {
  {"XjreOption", required_argument, NULL, 'b'},
  {"classpath", required_argument, NULL, 'p'},
  {"cp", required_argument, NULL, 'p'},
  {"help", no_argument, NULL, 'h'},
  {"version", no_argument, NULL, 'v'}
};

CommandLine::CommandLine(const int argc, char * const argv[]) {
  this->argc = argc;
  this->argv = argv;
}

void CommandLine::parse() {
  int val;

  optreset = optind = 1;
  while ((val = getopt_long_only(argc, argv, kOptString, kLongOpts, NULL)) != -1) {
    switch (val) {
      case 'h':
        help_flag_ = true;
        break;
      case 'v':
        version_flag_ = true;
        break;
      case 'p':
        cp_option_ = optarg;
        break;
      case 'b':
        xjre_option_ = optarg;
        break;
    }
  }

  argc -= optind;
  argv += optind;

  class_name_ = *argv;
  for (int i = 1; i < argc; i++) {
    args_.push_back(std::string(*(argv + i)));
  }
}
} // namespace my_jvm
