// Exercise 12.02:
// Write your own version of the StrBlob class
// including the const versions of front and back.
#include <iostream>
#include "exercise_12_02.h" //NOLINT
int main() {
  StrBlob b1;
  {
    StrBlob b2 = {"a", "an", "the"};
    b1 = b2;
    b2.push_back("about");
  }
  std::cout << b1.front() << " " << b1.back() << std::endl;
  // std::cout << b2.front() << " " << b2.back() << std::endl;
    return 0;
}
