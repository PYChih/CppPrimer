// Exercise 14.26
//  Define subscript operators for your StrVec,
//  String, StrBlob, and StrBlobPtr classes.
//  - String_14_26.h, String_14_26.cc
// g++ -c String_14_26.cc exercise_14_26_String.cc
// g++ String_14_26.o exercise_14_26_String.o && ./a.out
#include <string>
#include "String_14_26.h"
using std::cout;
using std::endl;
using std::string;
int main() {
  String s1("Hello world !");
  cout << s1 << endl;
  for (auto i = 0; i < s1.size(); ++i) {
    cout << s1[i];
    s1[i] = '0';
  }
  cout << endl;
  const String cs1("const Hello world");
  for (auto i = 0; i < cs1.size(); ++i) {
    cout << cs1[i];
  }
  cout << endl;
  cout << s1 << endl;
}