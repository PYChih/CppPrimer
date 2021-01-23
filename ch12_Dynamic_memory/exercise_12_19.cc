// Exercise 12.19
//  Define your own version of StrBlobPtr and
//  update your StrBlob class with the appropriate
//  friend declaration and begin and end members.
#include <iostream>
#include "exercise_12_19.h" //NOLINT
int main() {
  StrBlob b1;
  {
    StrBlob b2 = {"a", "an", "the"};
    b1 = b2;
    b2.push_back("about");
  }
  std::cout << b1.front() << " " << b1.back() << std::endl;
  // std::cout << b2.front() << " " << b2.back() << std::endl;
  std::cout << (b1.begin()).deref() << std::endl;
  return 0;
}
