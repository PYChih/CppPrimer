// Exercise 14.26
//  Define subscript operators for your StrVec,
//  String, StrBlob, and StrBlobPtr classes.
//  - StrVec_14_26.h, StrVec_14_26.cc
// g++ -c StrVec_14_26.cc exercise_14_26_StrVec.cc
// g++ StrVec_14_26.o exercise_14_26_StrVec.o && ./a.out
#include <iostream>
#include "StrVec_14_26.h"
using std::cout;
using std::endl;
int main() {
  StrVec sv{"Hello", "World", "!"};
  auto beg = sv.begin();
  while (beg != sv.end()) {
    cout << *beg++ << " ";
  }
  cout << endl;
  for (auto i = 0; i < sv.size(); ++i) {
    cout << sv[i] << " ";
  }
  cout << endl;
}