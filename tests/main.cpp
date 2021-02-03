#include <iostream>
#include "../utils/string_formatting/string_effects.h"
#include "../utils/string_formatting/string_coloring.h"

void test_strings(std::string name, std::string i, std::string b) {
  if (i != b) {
    std::cout << name << " failed: " << i << " != " << b << std::endl;
    std::exit(1);
  }
}

void test_string_effects() {
  test_strings("Bold", bold("test"), "\x1B[1mtest\x1B[0m");
  std::cout << "Bold passed." << std::endl;

  test_strings("Dimmed", dimmed("test"), "\x1B[2mtest\x1B[0m");
  std::cout << "Dimmed passed." << std::endl;

  test_strings("Italic", italic("test"), "\x1b[3mtest\x1b[0m");
  std::cout << "Italic passed." << std::endl;

  test_strings("Underline", underline("test"), "\x1b[4mtest\x1b[0m");
  std::cout << "Underline passed." << std::endl;

  test_strings("Blink", blink("test"), "\x1b[5mtest\x1b[0m");
  std::cout << "Blink passed." << std::endl;

  test_strings("Reverse", reverse("test"), "\x1b[7mtest\x1b[0m");
  std::cout << "Reverse passed." << std::endl;

  test_strings("Hidden", hidden("test"), "\x1b[8mtest\x1b[0m");
  std::cout << "Hidden passed." << std::endl;

  test_strings("Stricken", stricken("test"), "\x1b[9mtest\x1b[0m");
  std::cout << "Stricken passed." << std::endl;

  std::cout << "All text effect tests passed." << std::endl;
}


int main() {
  test_string_effects();
  return 0;
}
