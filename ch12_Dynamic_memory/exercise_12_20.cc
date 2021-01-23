// Exercise 12.20
//  Write a program that reads an input file a line at a time into
//  a StrBlob and uses a StrBlobPtr to print each element in that StrBlob.
#include <iostream>
#include <fstream>
#include "exercise_12_20.h" //NOLINT
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
