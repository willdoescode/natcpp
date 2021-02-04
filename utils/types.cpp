//
// Created by Will Lane on 2/3/21.
//

#include "types.h"
#include "fs/handle_files.h"
#include <string>
#include <utility>
#include <vector>
#include <fstream>
#include <filesystem>
#include <sys/stat.h>
#include <grp.h>
#include <pwd.h>
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

std::string File :: doit() {
  return this->user;
}

Directory :: Directory (const std::string& path) {
  std::vector<File> hold = {};
  std::vector<fs::directory_entry> phold = get_files(path);

  for (const fs::directory_entry& i : phold) {
    std::vector<FileMetaType> meta_types = {};
    if (i.is_directory())
      meta_types.push_back(FileMetaType::Dir);

    if (i.is_symlink())
      meta_types.push_back(FileMetaType::Symlink);

    if (i.is_fifo())
      meta_types.push_back(FileMetaType::Pipe);

    if (i.is_character_file())
      meta_types.push_back(FileMetaType::CharD);

    if (i.is_block_file())
      meta_types.push_back(FileMetaType::BlockD);

    if (i.is_socket())
      meta_types.push_back(FileMetaType::Socket);

    if (meta_types.empty())
      meta_types.push_back(FileMetaType::Path);

    struct stat info{};
    stat(i.path().c_str(), &info);
    struct group *gr = getgrgid(info.st_gid);
    struct tm *timeinfo = localtime((const time_t *) info.st_ctime);
    struct passwd *pws = getpwuid(info.st_uid);


    hold.push_back(
      new File (
        i,
        meta_types,
        gr->gr_name,
        pws->pw_name,
        i.last_write_time(),
        timeinfo->tm_year,
        i.file_size(),
        fs::status(i.path()).permissions()
      )
    );
  }
  this->paths = paths;
}
