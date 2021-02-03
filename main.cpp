#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include "args/cli_args.h"
namespace fs = std::filesystem;

auto get_files(const std::string& dir_name) {
  std::vector<fs::directory_entry> res = {};
  for (const auto& f : fs::directory_iterator(dir_name))
    res.push_back(f);
  return res;
}

int main(int argc, char* argv[]) {
  auto args = parse_args();
  std::vector<fs::directory_entry> f = get_files(".");
  for (const fs::directory_entry& i : f)
    std::cout << i.path() << std::endl;
  return 0;
}
