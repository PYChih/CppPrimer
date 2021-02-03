// Exercise 12.19
//  Define your own version of StrBlobPtr and
//  update your StrBlob class with the appropriate
//  friend declaration and begin and end members.
// StrBlobPtr_12_19.cc StrBlobPtr_12_19.h
// g++ -c StrBlobPtr_12_19.cc exercise_12_19.cc
// g++ StrBlobPtr_12_19.o exercise_12_19.o && ./a.out
#include <iostream>
#include "StrBlobPtr_12_19.h" //NOLINT
int main() {
  StrBlob b1;
  {
    StrBlob b2 = {"a", "an", "the"};
    b1 = b2;
    b2.push_back("about");
  }
  std::cout << b1.front() << " " << b1.back() << std::endl;
  std::cout << (b1.begin()).deref() << std::endl;
  return 0;
}
