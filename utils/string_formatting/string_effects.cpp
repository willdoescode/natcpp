//
// Created by Will Lane on 2/2/21.
//

#include "string_effects.h"
#include <string>

std::string bold(const std::string& input) {
  return "\x1B[1m" + input + "\x1B[0m";
}

std::string dimmed(const std::string& input) {
  return "\x1B[2m" + input + "\x1B[0m";
}

std::string italic(const std::string& input) {
  return "\x1B[3m" + input + "\x1B[0m";
}

std::string underline(const std::string& input) {
  return "\x1B[4m" + input + "\x1B[0m";
}

std::string blink(const std::string& input) {
  return "\x1B[5m" + input + "\x1B[0m";
}

std::string reverse(const std::string& input) {
  return "\x1B[7m" + input + "\x1B[0m";
}

std::string hidden(const std::string& input) {
  return "\x1B[8m" + input + "\x1B[0m";
}

std::string stricken(const std::string& input) {
  return "\x1B[9m" + input + "\x1B[0m";
}
