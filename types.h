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

struct File {
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
    fs::directory_entry p,
    std::vector<FileMetaType> m,
    std::string g,
    std::string u,
    std::string md,
    std::string c,
    std::string s,
    std::string ps
    ) {
    path = std::move(p);
    meta_types = std::move(m);
    group = std::move(g);
    user = std::move(u);
    modified = std::move(md);
    created = std::move(c);
    size = std::move(s);
    perms = std::move(ps);
  }
  ~File() = default;
  std::string doit() {
    return this->path.path();
  };
};

struct Directory {
private:
  std::vector<File> paths;
};
#endif //NATCPP_TYPES_H
