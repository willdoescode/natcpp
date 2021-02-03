cmake_minimum_required(VERSION 3.19)
project(natcpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(natcpp main.cpp args/cli_args.cpp args/cli_args.h types.h)