// Exercise 14.06
//  Define an output operator for your Sales_data class.
// Sales_data_14_06.h, Sales_data_14_06.cc
// g++ -c exercise_14_06.cc Sales_data_14_06.cc
// g++ exercise_14_06.o Sales_data_14_06.o && ./a.out < data/book_sales
#include "Sales_data_14_06.h"  // NOLINT
using std::cin;
using std::cout;
using std::endl;
int main() {
  Sales_data sd;
  while (read(cin, sd)) {
    cout << sd << endl;
  }
}
