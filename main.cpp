#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include "args/cli_args.h"
#include "types.h"
#include "utils/string_formatting/string_effects.h"
namespace fs = std::filesystem;

std::vector<fs::directory_entry> get_files(const std::string& dir_name) {
  std::vector<fs::directory_entry> res = {};
  for (const auto& f : fs::directory_iterator(dir_name))
    res.push_back(f);
  return res;
}

int main(int argc, char* argv[]) {
  auto args = parse_args();
  auto f = get_files(".");

  auto cool = new File(f[0], {Directory}, "1", "2", "3", "4", "5", "6");
  std::cout << cool->doit() << std::endl;

  std::cout << bold("hello") << std::endl;
  std::cout << underline("world") << std::endl;

  return 0;
}
