// Exercise 12.22
//  What changes would need to be made to StrBlobPtr to create a class
//  that can be used with a const StrBlob?
//  Define a class named ConstStrBlobPtr that can point to a const StrBlob.
// g++ -c exercise_12_22.cc StrBlobPtr_12_22.cc
// g++ exercise_12_22.o StrBlobPtr_12_22.o && ./a.out
#include <iostream>
#include "StrBlobPtr_12_22.h"  //NOLINT
using std::cout;
using std::endl;
int main() {
  const StrBlob b = {"Hello", "world", "const", "!"};
  ConstStrBlobPtr sp_begin = b.begin();
  for (int i = 0; i < b.size(); ++i) {
    cout << sp_begin.deref() << " ";
    sp_begin.incr();
  }
  cout << endl;
  return 0;
}
