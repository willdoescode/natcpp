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

  fs::directory_entry get_path();
  std::vector<FileMetaType> get_meta_types();
  std::string get_group();
  std::string get_user();
  std::string get_modified();
  std::string get_created();
  std::string get_size();
  std::string get_perms();

  void set_path(fs::directory_entry);
  void set_meta_types(std::vector<FileMetaType>);
  void set_group(std::string);
  void set_user(std::string);
  void set_modified(std::string);
  void set_created(std::string);
  void set_size(std::string);
  void set_perms(std::string);
};

class Directory {
private:
  std::vector<File> paths;
public:
  explicit Directory(const std::string&, bool);
  ~Directory() = default;

  std::vector<File> get_paths();
  void show_ls(bool);
};
#endif //NATCPP_TYPES_H
