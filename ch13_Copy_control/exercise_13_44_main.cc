#include <iostream>
#include "exercise_13_44.h"  //NOLINT
using std::cout;
using std::endl;
int main() {
  String s("aaa");
  s.push_back('c');
  auto beg = s.begin(), end = s.end();
  while (beg != end) {
      cout << *beg++ << endl;
  }
}
