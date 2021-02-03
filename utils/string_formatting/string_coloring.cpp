//
// Created by Will Lane on 2/2/21.
//

#include "string_coloring.h"
#include <string>

std::string red(const std::string& input) {
  return "\033[31;31m" + input + "\033[0m";
}

std::string yellow(const std::string& input) {
  return "\033[33;33m" + input + "\033[0m";
}

std::string magenta(const std::string& input) {
  return "\033[35;35m" + input + "\033[0m";
}

std::string dark_blue(const std::string& input) {
  return "\033[94;94m" + input + "\033[0m";
}

std::string light_blue(const std::string& input) {
  return "\033[34;34m" + input + "\033[0m";
}

std::string grey(const std::string& input) {
  return "\033[90;90m" + input + "\033[0m";
}

std::string green(const std::string& input) {
  return "\033[32;32m" + input + "\033[0m";
}
