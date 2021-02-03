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

  auto cool = new File(f[0], {Directory}, "1", "2", "3", "4", "5", "6");
  std::cout << cool->doit() << std::endl;

  return 0;
}
