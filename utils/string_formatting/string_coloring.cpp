//
// Created by Will Lane on 2/2/21.
//

#include "string_coloring.h"
#include <string>

std::string red(const std::string& input) {
  return "\033[1;31m" + input + "\033[0m";
}