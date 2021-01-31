#include <iostream>
#include "exercise_13_47.h"  //NOLINT
using std::cout;
using std::endl;
int main() {
  String s("aaa"), s2(s), s3 = s;
  s3 = s2;
  s.push_back('c');
  auto beg = s.begin(), end = s.end();
  while (beg != end) {
      cout << *beg++ << endl;
  }
}
