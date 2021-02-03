// Exercise 14.07
//  Define an output operator for you String class
//  you wrote for the exercises in 13.5 (p. 531).
// String_14_07.h, String_14_07.cc
// g++ -c String_14_07.cc exercise_14_07.cc
// g++ String_14_07.o exercise_14_07.o && ./a.out
#include "String_14_07.h"
using std::cout;
using std::endl;
int main() {
  String s("Hello");
  // auto beg = s.begin(), end = s.end();
  // while (beg != end) {
  //     cout << *beg++ << endl;
  // }
  cout << s << endl;
}
