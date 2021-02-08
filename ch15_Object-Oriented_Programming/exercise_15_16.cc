// Exercise 15_16
//  Rewrite the class representing a limited discount
//  strategy, which you wrote for the exercises
//  in § 15.2.2 (p. 601), to inherit from Disc_quote.
// Quote_15_16.cc Quote_15_16.h
// g++ -c exercise_15_16.cc Quote_15_16.cc
// g++ exercise_15_16.o Quote_15_16.cc && ./a.out
#include "Quote_15_16.h"
using std::cout;
using std::endl;
int main() {
  Quote base("999-999", 10);
  Bulk_quote derived("999-999", 10, 100, 0.1);
  Limit_quote limit("999-999", 10, 100, 0.1);
  // Disc_quote("999-999", 10, 100, 0.1);
  print_total(cout, base, 100);
  print_total(cout, derived, 100);
  print_total(cout, limit, 100);
  derived.debug(cout) << endl;
  base.debug(cout) << endl;
}
