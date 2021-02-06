//
// Created by Will Lane on 2/3/21.
//

#include "types.h"
#include "fs/handle_files.h"
#include "string_formatting/string_coloring.h"
#include "string_formatting/string_effects.h"
#include <string>
#include <utility>
#include <vector>
#include <filesystem>
#include <sys/stat.h>
#include <grp.h>
#include <pwd.h>
#include <chrono>
#include <sstream>
#include <iostream>
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

File get_file_info(const fs::directory_entry& file) {
  std::vector<FileMetaType> meta_types = {};
  if (file.is_directory()) meta_types.push_back(FileMetaType::Dir);
  if (file.is_symlink()) meta_types.push_back(FileMetaType::Symlink);
  if (file.is_fifo()) meta_types.push_back(FileMetaType::Pipe);
  if (file.is_character_file()) meta_types.push_back(FileMetaType::CharD);
  if (file.is_block_file()) meta_types.push_back(FileMetaType::BlockD);
  if (file.is_socket()) meta_types.push_back(FileMetaType::Socket);
  if (meta_types.empty()) meta_types.push_back(FileMetaType::Path);

  struct stat info{};
  stat(file.path().c_str(), &info);
  struct group *gr = getgrgid(info.st_gid);
  auto created = posix2time(info.st_ctime);
  struct passwd *user = getpwuid(info.st_uid);

  std::tm *gat = std::gmtime(&created);
  std::stringstream buff;
  buff << std::put_time(gat, "%A, %d %B %Y %H:%M");
  std::string created_format = buff.str();

  std::string modified_formatted;

  try {
    std::time_t tt = decltype(file.last_write_time())::clock::to_time_t(file.last_write_time());
    std::tm *gmt = std::gmtime(&tt);
    std::stringstream buffer;
    buffer << std::put_time(gmt, "%A, %d %B %Y %H:%M");
    modified_formatted = buffer.str();
  } catch (fs::filesystem_error &e) {
    modified_formatted = "0 0 0 00 0 ";
  }

  std::string file_size;

  if (!file.is_directory()) {
    try {
      file_size = std::to_string(file.file_size());
    } catch (fs::filesystem_error &e) {
      file_size = grey("-");
    }
  } else {
    file_size = grey("-");
  }

  return File (
    file,
    meta_types,
    gr->gr_name,
    user->pw_name,
    modified_formatted,
    created_format,
    file_size,
    color_and_format_perms(fs::status(file.path()).permissions())
  );
}

bool sort_compare_file(File f1, File f2) {
  return f1.get_path().path().filename().string() < f2.get_path().path().filename().string();
}

Directory :: Directory (const std::string& path, bool sort) {
  std::vector<File> paths_h = {};

  if (fs::directory_entry(path).exists() && !fs::directory_entry(path).is_directory()) {
    paths_h.emplace_back(get_file_info(fs::directory_entry(path)));
  } else if(!fs::directory_entry(path).exists()) {
    std::cout << red("OS Error (2): Path does not exist.") << std::endl;
    std::exit(1);
  } else {
    for (const fs::directory_entry& i : get_files(path)) {
      paths_h.emplace_back(get_file_info(i));
    }
  }

  if (sort)
    std::sort(paths_h.begin(), paths_h.end(), sort_compare_file);

  this->paths = paths_h;
}

std::vector<File> Directory :: get_paths() {
  return this->paths;
}

void print_files(const std::vector<File>& files) {
  for (File file : files) {
    auto p = file.get_path();
    std::string path = p.path().filename().string();
    std::string perm_denote = ".";
    for (auto m : file.get_meta_types()) {
      switch (m) {
        case Dir:
          path = bold(light_blue(path) + "/");
          perm_denote = bold(dark_blue("d"));
          break;
        case Symlink:
          path = magenta(path);
          perm_denote = magenta("l");
          break;
        case Pipe:
          path = yellow(path);
          perm_denote = yellow("|");
          break;
        case CharD:
          path = green(path);
          perm_denote = green("c");
          break;
        case BlockD:
          path = underline(green(path));
          perm_denote = underline(green("b"));
          break;
        case Socket:
          path = underline(yellow(path));
          perm_denote = underline(yellow("s"));
          break;
        case Path:
          continue;
      }
    }

    // Set colors
    file.set_size(green(file.get_size()));
    file.set_group(yellow(file.get_group()));
    file.set_user(yellow(file.get_user()));
    file.set_modified(light_blue(file.get_modified()));

    std::cout << perm_denote + file.get_perms() << ' ';
    std::cout << file.get_size() << ' ';
    std::cout << file.get_group() << ' ';
    std::cout << file.get_user() << ' ';
    std::cout << file.get_modified() << ' ';
    std::cout << path << std::endl;
  }
}

void Directory :: show_ls(bool gdf) {
  std::vector<File> paths_h = this->get_paths();
  std::vector<File> dirs;
  std::vector<File> others;


  if (gdf) {
    for (File file : paths_h) {
      if (file.get_path().is_directory()) {
        dirs.emplace_back(file);
      } else {
        others.emplace_back(file);
      }
    }
    print_files(dirs);
    print_files(others);
  } else {
    print_files(paths_h);
  }
}
