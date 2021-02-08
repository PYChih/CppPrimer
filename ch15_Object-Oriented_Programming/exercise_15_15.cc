// Exercise 15_15
//  Add a virtual debug function to your Quote class
//  hierarchy that displays the data members
//  of the respective classes.
// Quote_15_15.cc Quote_15_15.h
// g++ -c exercise_15_15.cc Quote_15_15.cc
// g++ exercise_15_15.o Quote_15_15.cc && ./a.out
#include "Quote_15_15.h"
using std::cout;
using std::endl;
int main() {
  Quote base("999-999", 10);
  Bulk_quote derived("999-999", 10, 100, 0.1);
  // Disc_quote("999-999", 10, 100, 0.1);
  print_total(cout, base, 100);
  print_total(cout, derived, 100);
  derived.debug(cout) << endl;
  base.debug(cout) << endl;
}
