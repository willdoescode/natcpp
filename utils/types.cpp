//
// Created by Will Lane on 2/3/21.
//

#include "types.h"
#include <string>
#include <vector>

Directory :: Directory(const std::vector<File>& paths) {
  this->paths = paths;
}

File :: File (
  const fs::directory_entry& path,
  const std::vector<FileMetaType>& meta_types,
  const std::string& group,
  const std::string& user,
  const std::string& modified,
  const std::string& created,
  const std::string& size,
  const std::string& perms
  ) {
  this->path = path;
  this->meta_types = meta_types;
  this->group = group;
  this->user = user;
  this->modified = modified;
  this->created = created;
  this->size = size;
  this->perms = perms;
}

std::string File :: doit() {
  return this->user;
}
