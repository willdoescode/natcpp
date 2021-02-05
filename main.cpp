//
// Created by Will Lane on 2/2/21.
//

#include "include/CLI11.hpp"
#include "utils/types.h"

int main(int argc, char* argv[]) {
  CLI::App app{"natls c++"};
  std::string dir = ".";
  app.add_option("Directory", dir, "Input a file");

  CLI11_PARSE(app, argc, argv);

  (new Directory(dir))->show_ls();

  return 0;
}
