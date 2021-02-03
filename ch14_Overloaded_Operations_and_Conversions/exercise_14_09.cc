// Exercise 14.09
//  Define an input operator for your Sales_data class.
// Sales_data_14_09.h, Sales_data_14_09.cc
// g++ -c exercise_14_09.cc Sales_data_14_09.cc
// g++ exercise_14_09.o Sales_data_14_09.o && ./a.out < data/book_sales
#include "Sales_data_14_09.h"  // NOLINT
using std::cin;
using std::cout;
using std::endl;
int main() {
  Sales_data sd;
  while (cin >> sd) {
    cout << sd << endl;
  }
}
