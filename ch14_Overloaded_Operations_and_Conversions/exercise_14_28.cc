// Exercise 14.28
//  Define addition and subtraction for StrBlobPtr
//  so that these operators implement pointer arithmetic (3.5.3, p. 119).
// Exercise 14.27
//  Add increment and decrement operators to your StrBlobPtr class.
//  - StrBlobPtr_14_28.h, StrBlobPtr_14_28.cc
// g++ -c StrBlobPtr_14_28.cc exercise_14_28.cc
// g++ StrBlobPtr_14_28.o exercise_14_28.o && ./a.out
#include <iostream>
#include "StrBlobPtr_14_28.h"  //NOLINT
using std::cout;
using std::endl;
int main() {
  StrBlob a = {"Hello", "world", "!"};
  const StrBlob b = {"Hello", "world", "const", "!"};
  // create StrBlobPtr and ConstStrBlobPtr
  StrBlobPtr beg = a.begin();
  ConstStrBlobPtr cbeg = b.begin();
  // test != and ++
  while (beg != a.end()) {
    cout << (beg++).deref() << " ";
  }
  cout << endl;
  while (cbeg != b.end()) {
    cout << cbeg.deref() << " ";
    ++cbeg;
  }
  cout << endl;
  std::size_t sz = 2;
  StrBlobPtr cc = a.begin() + 2;
  StrBlobPtr dd = a.begin();
  dd+=1;
  cout << dd.deref() << endl;
  cout << cc.deref() << endl;
  return 0;
}
