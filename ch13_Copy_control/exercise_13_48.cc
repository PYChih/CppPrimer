#include <iostream>
#include <vector>
#include "exercise_13_47.h"  //NOLINT
using std::cout;
using std::endl;
using std::vector;
int main() {
  vector<String> sv;
  String s("aaa"), s2(s), s3 = s;
  s3 = s2;
  s.push_back('c');
  int i = 0;
  while (i < 100) {
      sv.push_back("c");
      ++i;
  }
  cout << sv.size() << endl;
}
