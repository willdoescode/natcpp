//
// Created by Will Lane on 2/2/21.
//

#include "args/cli_args.h"
#include "utils/types.h"

int main(int argc, char* argv[]) {
  (new Directory(parse_args(argc, argv)))->show_ls();

  return 0;
}
