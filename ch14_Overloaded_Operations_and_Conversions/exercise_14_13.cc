// Exercise 14.13
//  Which other arithmetic operators (Table 4.1 (p. 139)),
//  if any, do you think Sales_data ought to support?
//  Define any you think the class should include.
// add + and +=
// Sales_data_14_13.h, Sales_data_14_13.cc
// g++ -c exercise_14_13.cc Sales_data_14_13.cc
// g++ exercise_14_13.o Sales_data_14_13.o && ./a.out < data/add_item
#include "Sales_data_14_13.h"  // NOLINT
using std::cin;
using std::cout;
using std::endl;
int main() {
  Sales_data b1(cin), b2(cin);
  cout << "book1 " << b1 << endl;
  cout << "book2 " << b2 << endl;
  cout << "sum " << b1 + b2 << endl;
}
