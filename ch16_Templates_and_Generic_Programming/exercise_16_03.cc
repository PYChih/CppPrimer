// Exercise 16.3:
// Call your compare function on two Sales_data objects to see how your compiler
// handles errors during instantiation.
//  In instantiation of ‘int compare(const T&, const T&) [with T = Sales_data]’
//  error: no match for ‘operator<’ (
//  operand types are ‘const Sales_data’ and ‘const Sales_data’)
#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include "Sales_data_16_03.h"

template<typename T>
int compare(const T& lhs, const T& rhs) {
  if (lhs < rhs) return -1;
  if (rhs < lhs) return 1;
  return 0;
}
int main() {
  // Test compare function
  cout << compare(1, 0) << endl;
  cout << compare(Sales_data(), Sales_data());
}