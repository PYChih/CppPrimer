#include <iostream>
#include <vector>
#include "String.h"  //NOLINT
using std::cout;
using std::endl;
using std::vector;
int main() {
  String s("aaa"), s2(s), s3 = s;
  s3 = s2;
  s.push_back('c');
  int i = 0;
  while (i < 100) {
      s.push_back('c');
      ++i;
  }
  s3 = std::move(s);
  vector<String> sv;
  i = 0;
  while (i < 100) {
      sv.push_back("c");
      ++i;
  }
}
