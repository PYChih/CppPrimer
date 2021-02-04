// Exercise 14.32
//  Define a class that holds a pointer to a StrBlobPtr.
//  Define the overloaded arrow operator for that class.
//  - StrBlobPtr_14_32.h, StrBlobPtr_14_32.cc
// g++ -c StrBlobPtr_14_32.cc exercise_14_32.cc
// g++ StrBlobPtr_14_32.o exercise_14_32.o && ./a.out
#include <iostream>
#include "StrBlobPtr_14_32.h"  //NOLINT
using std::cout;
using std::endl;
int main() {
  StrBlob a = {"Hello", "world", "!"};
  const StrBlob b = {"Hello", "world", "const", "!"};
  // create StrBlobPtr and ConstStrBlobPtr
  StrBlobPtr beg = a.begin();
  ConstStrBlobPtr cbeg = b.begin();
  // test !=, ++ and *
  while (beg != a.end()) {
    cout << *beg++ << " ";
  }
  cout << endl;
  while (cbeg != b.end()) {
    cout << *cbeg << " ";
    cout << cbeg->size() << " ";
    ++cbeg;
  }
  cout << endl;
  StrBlobPtr testsbp = a.begin();
  PtrStrBlobPtr psbp(&testsbp);
  cout << *(*psbp) << endl;
  cout << *(psbp->incr()) << endl;
  return 0;
}
