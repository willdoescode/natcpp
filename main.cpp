//
// Created by Will Lane on 2/2/21.
//

#include "include/CLI11.hpp"
#include "utils/types.h"

int main(int argc, char* argv[]) {
  CLI::App app{"natls c++"};

  // CLI flag vars
  std::string dir = ".";
  bool gdf = false;
  bool sort = false;

  app.add_option("Directory", dir, "Input a file");
  app.add_flag("-g,--group-directories-first", gdf, "Do you want dirs first?");
  app.add_flag("-s,--sort", sort, "Sort by name");
  CLI11_PARSE(app, argc, argv);

  (new Directory(dir, sort))->show_ls(gdf);

  return 0;
}
