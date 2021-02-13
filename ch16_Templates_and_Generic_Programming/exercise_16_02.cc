// Exercise 16.2:
// Write and test your own versions of the compare functions.
#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;

template<typename T>
int compare(const T& lhs, const T& rhs) {
  if (lhs < rhs) return -1;
  if (rhs < lhs) return 1;
  return 0;
}
int main() {
  // Test compare function
  cout << compare(1, 0) << endl;
}