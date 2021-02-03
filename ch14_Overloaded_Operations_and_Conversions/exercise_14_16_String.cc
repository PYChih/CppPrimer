// Exercise 14.16
//  Define equality and inequality operators for your
//  StrBlob (12.1.1, p. 456),
//  StrBlobPtr (12.1.6, p. 474),
//  StrVec (13.5, p.526),
//  and String (13.5, p. 531) classes.
//  - String_14_16.h, String_14_16.cc
// g++ -c String_14_16.cc exercise_14_16_String.cc
// g++ String_14_16.o exercise_14_16_String.o && ./a.out
#include <vector>
#include "String_14_16.h"
using std::vector;

void foo(String x) {
  std::cout << x << std::endl;
}
String baz() {
  String ret("world");
  return ret;
}

int main() {
  char text[] = "world";
  String s0;
  String s1("hello");
  String s2(std::move(s0));
  String s3 = s1;
  String s4(text);
  s2 = s1;
  if (s2 == s1) std::cout << "s2 == s1" << std::endl;
  foo(s1);
  foo("temporary");
  String s5 = baz();
  std::vector<String> svec;
  svec.push_back(s1);
  svec.push_back(s2);
  svec.push_back(s3);
  svec.push_back(s4);
  svec.push_back(baz());
  svec.push_back("good job");
  for (const auto &s : svec) {
    std::cout << s << std::endl;
  }
  std::cout << "Input a string: ";
  String s6;
  std::cin >> s6;
  std::cout << s6 << std::endl;
}