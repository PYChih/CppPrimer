// Exercise 14.30
//  Add dereference and arrow operators to your StrBlobPtr class
//  and to the ConstStrBlobPtr class that you defined in
//  exercise 12.22 from 12.1.6 (p. 476).
//  Note that the operators in constStrBlobPtr must return
//  const references because the data member in
//  constStrBlobPtr points to a const vector.
//  - StrBlobPtr_14_30.h, StrBlobPtr_14_30.cc
// g++ -c StrBlobPtr_14_30.cc exercise_14_30.cc
// g++ StrBlobPtr_14_30.o exercise_14_30.o && ./a.out
#include <iostream>
#include "StrBlobPtr_14_30.h"  //NOLINT
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
  return 0;
}
