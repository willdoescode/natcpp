//
// Created by Will Lane on 2/3/21.
//

#include <iostream>
#include "../utils/string_formatting/string_effects.h"
#include "../utils/string_formatting/string_coloring.h"

void test_strings(std::string name, std::string i, std::string b) {
  if (i != b) {
    std::cout << red(name + " failed: " + i + " != " + b) << std::endl;
    std::exit(1);
  }
}

void test_string_effects() {
  test_strings("Bold", bold("test"), "\x1B[1mtest\x1B[0m");
  std::cout << green("../utils::string_formatting::string_effects.h::bold passed.") << std::endl;

  test_strings("Dimmed", dimmed("test"), "\x1B[2mtest\x1B[0m");
  std::cout << green("../utils::string_formatting::string_effects.h::dimmed passed.") << std::endl;

  test_strings("Italic", italic("test"), "\x1b[3mtest\x1b[0m");
  std::cout << green("../utils::string_formatting::string_effects.h::italic passed.") << std::endl;

  test_strings("Underline", underline("test"), "\x1b[4mtest\x1b[0m");
  std::cout << green("../utils::string_formatting::string_effects.h::underline passed.") << std::endl;

  test_strings("Blink", blink("test"), "\x1b[5mtest\x1b[0m");
  std::cout << green("../utils::string_formatting::string_effects.h::blank passed.") << std::endl;

  test_strings("Reverse", reverse("test"), "\x1b[7mtest\x1b[0m");
  std::cout << green("../utils::string_formatting::string_effects.h::reverse passed.") << std::endl;

  test_strings("Hidden", hidden("test"), "\x1b[8mtest\x1b[0m");
  std::cout << green("../utils::string_formatting::string_effects.h::hidden passed.") << std::endl;

  test_strings("Stricken", stricken("test"), "\x1b[9mtest\x1b[0m");
  std::cout << green("../utils::string_formatting::string_effects.h::stricken passed.") << std::endl;

  std::cout << green("All text effect tests passed.") << std::endl;
}

void test_string_colors() {
  test_strings("Red", red("test"), "\033[31;31mtest\033[0m");
  std::cout << green("../utils::string_formatting::string_coloring.h::red  passed.") << std::endl;

  test_strings("Yellow", yellow("test"), "\033[33;33mtest\033[0m");
  std::cout << green("../utils::string_formatting::string_coloring.h::yellow  passed.") << std::endl;

  test_strings("Magenta", magenta("test"), "\033[35;35mtest\033[0m");
  std::cout << green("../utils::string_formatting::string_coloring.h::magenta  passed.") << std::endl;

  test_strings("Dark Blue", dark_blue("test"), "\033[94;94mtest\033[0m");
  std::cout << green("../utils::string_formatting::string_coloring.h::dark_blue  passed.") << std::endl;

  test_strings("Light Blue", light_blue("test"), "\033[34;34mtest\033[0m");
  std::cout << green("../utils::string_formatting::string_coloring.h::light_blue  passed.") << std::endl;

  test_strings("Grey", grey("test"), "\033[90;90mtest\033[0m");
  std::cout << green("../utils::string_formatting::string_coloring.h::grey  passed.") << std::endl;

  test_strings("Green", green("test"), "\033[32;32mtest\033[0m");
  std::cout << green("../utils::string_formatting::string_coloring.h::green  passed.") << std::endl;

  std::cout << green("All text color tests passed.") << std::endl;
}

int main() {
  test_string_effects();
  test_string_colors();
  return 0;
}
