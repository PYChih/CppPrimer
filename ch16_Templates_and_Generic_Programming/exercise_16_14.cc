// Exercise 16.14:
// Write a Screen class template that uses nontype parameters to define the
// height and width of the Screen.
#include <iostream>
#include "Screen_16_14.h"
using std::cout;
int main() {
  Screen<10, 10> sc(' ');
  sc.set(5, 5, 'a');
  // sc.set('a');
  cout << sc;
}