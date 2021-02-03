// Exercise 14.16
//  Define equality and inequality operators for your
//  StrBlob (12.1.1, p. 456),
//  StrBlobPtr (12.1.6, p. 474),
//  StrVec (13.5, p.526),
//  and String (13.5, p. 531) classes.
//  - StrBlobPtr_14_16.h, StrBlobPtr_14_16.cc
// g++ -c StrBlobPtr_14_16.cc exercise_14_16_StrBlobPtr.cc
// g++ StrBlobPtr_14_16.o exercise_14_16_StrBlobPtr.o && ./a.out
#include <iostream>
#include "StrBlobPtr_14_16.h"  //NOLINT
using std::cout;
using std::endl;
int main() {
  const StrBlob b = {"Hello", "world", "const", "!"};
  const StrBlob c = {"Hello", "world", "const", "!"};
  auto d = c;
  cout << "test for strblob ";
  cout << (b == c) << endl;
  cout << (d == c) << endl;
  ConstStrBlobPtr sp_begin = b.begin();
  while (sp_begin != b.end()) {
    cout << sp_begin.deref() << " ";
    sp_begin.incr();
  }
  cout << endl;
  return 0;
}
