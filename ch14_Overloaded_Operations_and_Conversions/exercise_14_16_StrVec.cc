// Exercise 14.16
//  Define equality and inequality operators for your
//  StrBlob (12.1.1, p. 456),
//  StrBlobPtr (12.1.6, p. 474),
//  StrVec (13.5, p.526),
//  and String (13.5, p. 531) classes.
//  - StrVec_14_16.h, StrVec_14_16.cc
// g++ -c StrVec_14_16.cc exercise_14_16_StrVec.cc
// g++ StrVec_14_16.o exercise_14_16_StrVec.o && ./a.out
#include <iostream>
#include "StrVec_14_16.h"
int main() {
  StrVec vec;
  vec.reserve(6);
  std::cout << "capacity(reserve to 6): " << vec.capacity() << std::endl;
  vec.reserve(4);
  std::cout << "capacity(reserve to 4): " << vec.capacity() << std::endl;
  vec.push_back("hello");
  vec.push_back("world");
  vec.resize(4);
  for (auto i = vec.begin(); i != vec.end(); ++i)
    std::cout << *i << std::endl;
  std::cout << "-EOF-" << std::endl;
  vec.resize(1);
  for (auto i = vec.begin(); i != vec.end(); ++i)
    std::cout << *i << std::endl;
  std::cout << "-EOF-" << std::endl;
  StrVec vec_list{ "hello", "world", "ooo" };
  for (auto i = vec_list.begin(); i != vec_list.end(); ++i)
    std::cout << *i << " ";
  std::cout << std::endl;
  // Test operator==
  const StrVec const_vec_list{ "hello", "world", "ooo" };
  if (vec_list == const_vec_list) {
    for (const auto &str : const_vec_list)
      std::cout << str << " ";
  std::cout << std::endl;
  }
}