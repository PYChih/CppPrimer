// Exercise 13.58
//  Write versions of class Foo with print statements in their sorted functions to test your answers to the previous two exercises.
#include "Foo.h"
#include <vector>
#include <algorithm>
using std::vector;
int main() {
  Foo foo1;
  foo1.sorted();
  std::move(foo1).sorted();
}
