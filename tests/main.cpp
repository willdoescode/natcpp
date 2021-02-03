#include <iostream>
#include "../utils/string_formatting/string_effects.h"
#include "../utils/string_formatting/string_coloring.h"

void test_string_effects() {
  std::cout << bold("hellow rodl") << std::endl;
  std::cout << red("hellow rodl") << std::endl;
}

int main() {
  test_string_effects();
  return 0;
}

