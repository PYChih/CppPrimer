// Exercise 14.18
//  Define relational operators for your
//  StrBlob, StrBlobPtr,
//  StrVec,
//  and String classes.
//  - StrVec_14_18.h, StrVec_14_18.cc
// g++ -c StrVec_14_18.cc exercise_14_18_StrVec.cc
// g++ StrVec_14_18.o exercise_14_18_StrVec.o && ./a.out
#include <iostream>
#include "StrVec_14_18.h"
using std::cout;
using std::endl;
int main() {
  StrVec sv1{"a", "b"}, sv2{"a", "b", "c"};
  cout << (sv1 < sv2) << endl;
  cout << (sv1 > sv2) << endl;
}