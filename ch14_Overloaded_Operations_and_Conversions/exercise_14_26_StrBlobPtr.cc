// Exercise 14.26
//  Define subscript operators for your StrVec,
//  String, StrBlob, and StrBlobPtr classes.
//  - StrBlobPtr_14_26.h, StrBlobPtr_14_26.cc
// g++ -c StrBlobPtr_14_26.cc exercise_14_26_StrBlobPtr.cc
// g++ StrBlobPtr_14_26.o exercise_14_26_StrBlobPtr.o && ./a.out
#include <iostream>
#include "StrBlobPtr_14_26.h"  //NOLINT
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
  cout << b[0] << endl;
  cout << c[1] << endl;
  cout << sp_begin[0] << endl;
  // cout << sp_begin.deref() << endl;
  int arr[] = {1, 2, 3, 4, 5};
  for (auto i : arr) {
    cout << i << " ";
  }
  cout << endl;
  cout << arr[1] << endl;
  cout << *(arr+1) << endl;
  cout << (arr+1)[0] << endl;
  cout << "[] for pointer " << endl;
  int i = 4;
  int *ip = &i;
  cout << ip[1] << endl;
  return 0;
}
