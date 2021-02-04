// Exercise 14.23
//  Define an initializer_list assignment operator
//  for your version of the StrVec class.
//  - StrVec_14_23.h, StrVec_14_23.cc
// g++ -c StrVec_14_23.cc exercise_14_23.cc
// g++ StrVec_14_23.o exercise_14_23.o && ./a.out
#include <iostream>
#include "StrVec_14_23.h"
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
  vec_list = {"initializer", "list", "assignment", "operator"};
  for (const auto &str : vec_list)
    std::cout << str << " ";
  std::cout << std::endl;
}