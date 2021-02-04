//
// Created by Will Lane on 2/2/21.
//

#ifndef NATCPP_TYPES_H
#define NATCPP_TYPES_H

#include <filesystem>
#include <utility>
#include <vector>
#include <string>
namespace fs = std::filesystem;

enum FileMetaType {
  Dir,
  Symlink,
  Path,
  Pipe,
  CharD,
  BlockD,
  Socket,
};

enum SortBy {
  Name,
  Created,
  Size,
  None,
};

class File {
private:
  fs::directory_entry path;
  std::vector<FileMetaType> meta_types;
  std::string group;
  std::string user;
  std::string modified;
  std::string created;
  std::string size;
  std::string perms;

public:
  File (
    const fs::directory_entry&,
    const std::vector<FileMetaType>&,
    const std::string&,
    const std::string&,
    const std::string&,
    const std::string&,
    const std::string&,
    const std::string&
    );

  ~File() = default;

  std::string doit();
};

class Directory {
private:
  std::vector<File> paths;
public:
  explicit Directory(const std::string&);
  ~Directory() = default;

  std::vector<File> get_paths();
};
#endif //NATCPP_TYPES_H
