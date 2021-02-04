// Exercise 14.18
//  Define relational operators for your
//  StrBlob, StrBlobPtr,
//  StrVec,
//  and String classes.
//  - String_14_18.h, String_14_18.cc
// g++ -c String_14_18.cc exercise_14_18_String.cc
// g++ String_14_18.o exercise_14_18_String.o && ./a.out
#include <string>
#include "String_14_18.h"
using std::cout;
using std::endl;
using std::string;
int main() {
  char text[] = "world";
  String s0;
  String s1("hello");
  String s2(text);
  cout << s1 << " " << s2 << endl;
  string ss1("hello"), ss2("world");
  //  w > h
  cout << ss1 << " " << ss2 << endl;
  cout << (ss1 < ss2) << endl;
  cout << (s1 < s2) << endl;
  cout << (s1 > s2) << endl;
}