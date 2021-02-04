//
// Created by Will Lane on 2/3/21.
//

#include "types.h"
#include "fs/handle_files.h"
#include "string_formatting/string_coloring.h"
#include <string>
#include <utility>
#include <vector>
#include <filesystem>
#include <sys/stat.h>
#include <grp.h>
#include <pwd.h>
#include <chrono>
#include <sstream>
namespace fs = std::filesystem;

File :: File (
  const fs::directory_entry & path,
  const std::vector<FileMetaType> & meta_types,
  const std::string & group,
  const std::string & user,
  const std::string & modified,
  const std::string & created,
  const std::string & size,
  const std::string & perms
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

std::string color_and_format_perms(fs::perms p) {
  std::string res;
  if ((p & fs::perms::owner_read) != fs::perms::none) {
    res.append(yellow("r"));
  } else {
    res.append(grey("-"));
  }

  if ((p & fs::perms::owner_write) != fs::perms::none) {
    res.append(red("w"));
  } else {
    res.append(grey("-"));
  }

  if ((p & fs::perms::owner_exec) != fs::perms::none) {
    res.append(green("x"));
  } else {
    res.append(grey("-"));
  }

  if ((p & fs::perms::group_read) != fs::perms::none) {
    res.append(yellow("r"));
  } else {
    res.append(grey("-"));
  }

  if ((p & fs::perms::group_write) != fs::perms::none) {
    res.append(red("w"));
  } else {
    res.append(grey("-"));
  }

  if ((p & fs::perms::group_exec) != fs::perms::none) {
    res.append(green("x"));
  } else {
    res.append(grey("-"));
  }

  if ((p & fs::perms::others_read) != fs::perms::none) {
    res.append(yellow("r"));
  } else {
    res.append(grey("-"));
  }

  if ((p & fs::perms::others_write) != fs::perms::none) {
    res.append(red("w"));
  } else {
    res.append(grey("-"));
  }

  if ((p & fs::perms::others_exec) != fs::perms::none) {
    res.append(green("x"));
  } else {
    res.append(grey("-"));
  }

  return res;
}

Directory :: Directory (const std::string& path) {
  std::vector<File> paths_h = {};

  for (const fs::directory_entry& i : get_files(path)) {
    std::vector<FileMetaType> meta_types = {};
    if (i.is_directory()) meta_types.push_back(FileMetaType::Dir);
    if (i.is_symlink()) meta_types.push_back(FileMetaType::Symlink);
    if (i.is_fifo()) meta_types.push_back(FileMetaType::Pipe);
    if (i.is_character_file()) meta_types.push_back(FileMetaType::CharD);
    if (i.is_block_file()) meta_types.push_back(FileMetaType::BlockD);
    if (i.is_socket()) meta_types.push_back(FileMetaType::Socket);
    if (meta_types.empty()) meta_types.push_back(FileMetaType::Path);

    struct stat info{};
    stat(i.path().c_str(), &info);
    struct group *gr = getgrgid(info.st_gid);
    auto created = posix2time(info.st_ctime);
    struct passwd *user = getpwuid(info.st_uid);

    std::tm *gat = std::gmtime(&created);
    std::stringstream buff;
    buff << std::put_time(gat, "%A, %d %B %Y %H:%M");
    std::string created_format = buff.str();

    std::time_t tt = decltype(i.last_write_time())::clock::to_time_t(i.last_write_time());
    std::tm *gmt = std::gmtime(&tt);
    std::stringstream buffer;
    buffer << std::put_time(gmt, "%A, %d %B %Y %H:%M");
    std::string modified_formatted = buffer.str();

    std::string file_size;

    if (i.is_directory()) {
      file_size.append(std::to_string(i.file_size()));
    } else {
      file_size.append(grey("-"));
    }

    paths_h.emplace_back(
      File (
        i,
        meta_types,
        gr->gr_name,
        user->pw_name,
        modified_formatted,
        created_format,
        file_size,
        color_and_format_perms(fs::status(i.path()).permissions())
      )
    );
  }
  this->paths = paths_h;
}

std::vector<File> Directory :: get_paths() {
  return this->paths;
}
