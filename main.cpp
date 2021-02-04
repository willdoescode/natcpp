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
  for (File file : dir->get_paths()) {
    std::cout << file.get_perms() << ' ';
    std::cout << file.get_size() << ' ';
    std::cout << file.get_group() << ' ';
    std::cout << file.get_user() << ' ';
    std::cout << file.get_modified() << ' ';
    std::cout << file.get_path().path() << std::endl;
  }

  return 0;
}
