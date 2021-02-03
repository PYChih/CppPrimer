// Exercise 14.18
//  Define relational operators for your
//  StrBlob, StrBlobPtr,
//  StrVec,
//  and String classes.
//  - StrBlobPtr_14_18.h, StrBlobPtr_14_18.cc
// g++ -c StrBlobPtr_14_18.cc exercise_14_18_StrBlobPtr.cc
// g++ StrBlobPtr_14_18.o exercise_14_18_StrBlobPtr.o && ./a.out
#include <iostream>
#include "StrBlobPtr_14_18.h"  //NOLINT
using std::cout;
using std::endl;
int main() {
  const StrBlob b = {"Hello", "world", "const", "!"};
  const StrBlob c = {"Hello", "world", "const", "!"};
  auto d = c;
  cout << "test for strblob ";
  cout << (b < c) << endl;
  cout << (d < c) << endl;
  ConstStrBlobPtr sp_begin = b.begin();
  while (sp_begin != b.end()) {
    cout << sp_begin.deref() << " ";
    sp_begin.incr();
    cout << (sp_begin < b.end()) << endl;
  }
  cout << endl;
  return 0;
}
