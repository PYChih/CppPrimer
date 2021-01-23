// Exercise 12.22
//  What changes would need to be made to StrBlobPtr to create a class
//  that can be used with a const StrBlob?
//  Define a class named ConstStrBlobPtr that can point to a const StrBlob.
#include <iostream>
#include <fstream>
#include "exercise_12_22.h" //NOLINT
using std::ifstream;
using std::cout;
using std::endl;
int main() {
  ifstream f("data/google_blog");
  StrBlob content;
  string s;
  while (f >> s) {
      content.push_back(s);
  }
  StrBlobPtr sp_begin = content.begin(), sp_end = content.end();
  for (auto i=0; i < content.size(); ++i) {
      cout << sp_begin.deref() << " ";
      sp_begin.incr();
  }
  cout << endl;
  return 0;
}
