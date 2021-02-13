// Exercise 16.7:
// Write a constexpr template that returns the size of a given array.
#include <iostream>
using std::endl;
using std::cout;
template<typename T, unsigned sz>
constexpr unsigned getSize(const T(&)[sz]) {
  return sz;
}
int main() {
  int arr[] = {1, 2, 3, 4, 5};
  cout << getSize(arr) << endl;
}