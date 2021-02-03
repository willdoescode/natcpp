//
// Created by Will Lane on 2/3/21.
//

#ifndef NATCPP_HANDLE_FILES_H
#define NATCPP_HANDLE_FILES_H

#include <filesystem>
#include <vector>
#include <string>
namespace fs = std::filesystem;

std::vector<fs::directory_entry> get_files(const std::string&);

#endif //NATCPP_HANDLE_FILES_H
