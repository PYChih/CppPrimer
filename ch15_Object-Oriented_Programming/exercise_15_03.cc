// Exercise 15_03
//  Define your own versions of the Quote class
//  and the print_total function.
// Quote_15_03.cc Quote_15_03.h
// g++ -c exercise_15_03.cc Quote_15_03.cc
// g++ exercise_15_03.o Quote_15_03.cc && ./a.out
#include "Quote_15_03.h"
using std::cout;
using std::endl;
int main() {
  Quote base("999-999", 10);
  Bulk_quote derived("999-999", 10, 100, 0.1);
  print_total(cout, base, 100);
  print_total(cout, derived, 100);
}
