// Exercise 14.22
//  Define a version of the assignment operator
//  that can assign a string representing an ISBN to a Sales_data.
// Sales_data_14_22.h, Sales_data_14_22.cc
// g++ -c exercise_14_22.cc Sales_data_14_22.cc
// g++ exercise_14_22.o Sales_data_14_22.o && ./a.out
#include "Sales_data_14_22.h"  // NOLINT
using std::cin;
using std::cout;
using std::endl;
int main() {
  Sales_data b1("000-000-0"), b2;
  cout << b1 << endl;
  cout << b2 << endl;
  b2 = "111-111-1";
  cout << b2 << endl;
}