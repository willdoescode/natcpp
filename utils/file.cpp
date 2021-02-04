//
// Created by Will Lane on 2/4/21.
//

#include "types.h"
#include <vector>
#include <filesystem>
#include <string>
namespace fs = std::filesystem;

fs::directory_entry File :: get_path() {
  return this->path;
}

std::vector<FileMetaType> File :: get_meta_types() {
  return this->meta_types;
}

std::string File :: get_group() {
  return this->group;
}

std::string File :: get_user() {
  return this->user;
}

std::string File :: get_modified() {
  return this->modified;
}

std::string File :: get_created() {
  return this->created;
}

std::string File :: get_size() {
  return this->size;
}

std::string File :: get_perms() {
  return this->perms;
}

void File :: set_path(fs::directory_entry p) {
  this->path = std::move(p);
}

void File :: set_meta_types(std::vector<FileMetaType> m) {
  this->meta_types = std::move(m);
}

void File :: set_group(std::string g) {
  this->group = std::move(g);
}

void File :: set_user(std::string u) {
  this->user = u;
}

void File :: set_modified(std::string m) {
  this->modified = std::move(m);
}

void File :: set_created(std::string c) {
  this->created = std::move(c);
}

void File :: set_size(std::string s) {
  this->size = std::move(s);
}

void File :: set_perms(std::string p) {
  this->perms = std::move(p);
}
