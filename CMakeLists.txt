cmake_minimum_required(VERSION 3.19)
project(natcpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(natcpp main.cpp args/cli_args.cpp args/cli_args.h types.h utils/string_formatting/string_effects.cpp utils/string_formatting/string_effects.h utils/string_formatting/string_coloring.cpp utils/string_formatting/string_coloring.h utils/fs/handle_files.cpp utils/fs/handle_files.h)