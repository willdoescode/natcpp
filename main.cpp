//
// Created by Will Lane on 2/2/21.
//

//#include <filesystem>
//#include <vector>
#include <iostream>
#include <string>
#include "args/cli_args.h"
#include "utils/types.h"
#include "utils/fs/handle_files.h"
namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
  auto args = parse_args();
  auto f = get_files(".");

  auto dir = new Directory(".");
  std::cout << dir->get_paths()[0].doit() << std::endl;

  return 0;
}
