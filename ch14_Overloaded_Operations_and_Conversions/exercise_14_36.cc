// Exercise 14.35
//  Use the class from the previous exercise
//  to read the standard input, storing each line as an element in a vector.
#include <vector>
#include "exercise_14_36.h"  // NOLINT
int main() {
  ReadString rs;
  std::vector<std::string> svec;
  std::string str;
  int i = 0;
  while (std::cin) {
    std::cout << "while cnt " << i << std::endl;
    ++i;
    str = rs();
    if (str != "") {
      svec.push_back(str);
    }
  }
  for (auto i : svec) {
    std::cout << i << std::endl;
  }
}
