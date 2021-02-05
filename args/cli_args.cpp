//
// Created by Will Lane on 2/2/21.
//

#include "cli_args.h"
#include "../utils/string_formatting/string_coloring.h"
#include <string>
#include <iostream>
#include <vector>
#include <filesystem>
namespace fs = std::filesystem;

std::string parse_args(int argc, char* argv[]) {
  std::cout << argc << std::endl;
  if (argc <= 1) return ".";
  return "/Users/willlane/dev/nat";
}
