// Exercise 15_11
//  Add a virtual debug function to your Quote class
//  hierarchy that displays the data members
//  of the respective classes.
// Quote_15_11.cc Quote_15_11.h
// g++ -c exercise_15_11.cc Quote_15_11.cc
// g++ exercise_15_11.o Quote_15_11.cc && ./a.out
#include "Quote_15_11.h"
using std::cout;
using std::endl;
int main() {
  Quote base("999-999", 10);
  Bulk_quote derived("999-999", 10, 100, 0.1);
  print_total(cout, base, 100);
  print_total(cout, derived, 100);
  derived.debug(cout) << endl;
  base.debug(cout) << endl;
}
