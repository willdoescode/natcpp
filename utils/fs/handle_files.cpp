//
// Created by Will Lane on 2/3/21.
//

#include "handle_files.h"
#include <filesystem>
#include <vector>
#include <string>
namespace fs = std::filesystem;

std::vector<fs::directory_entry> get_files(const std::string& dir_name) {
  std::vector<fs::directory_entry> res = {};
  for (const auto& f : fs::directory_iterator(dir_name))
    res.push_back(f);
  return res;
}
