// Exercise 15_26
//  Define the Quote and Bulk_quote copy-control members
//  to do the same job as the synthesized versions.
//  Give them and the other constructors print statements
//  that identify which function is running.
//  Write programs using these classes and predict what objects
//  will be created and destroyed.
//  Compare your predictions with the output
//  and continue experimenting until your predictions are reliably correct.
// Quote_15_26.cc Quote_15_26.h
// g++ -c exercise_15_26.cc Quote_15_26.cc
// g++ exercise_15_26.o Quote_15_26.cc && ./a.out
#include "Quote_15_26.h"
using std::cout;
using std::endl;
int main() {
  // Quote base("999-999", 10);
  // Bulk_quote derived("999-999", 10, 100, 0.1);
  // Limit_quote limit("999-999", 10, 100, 0.1);
  // // Disc_quote("999-999", 10, 100, 0.1);
  // print_total(cout, base, 100);
  // print_total(cout, derived, 100);
  // print_total(cout, limit, 100);
  // derived.debug(cout) << endl;
  // base.debug(cout) << endl;
  // Quote base;  // Quote default constructor and I'm Quote destructor
  // Bulk_quote derived;  // synthesis call Quote default constuctor
  // Quote base2("2-2", 2);
  // Quote base3;
  // base3 = base2;
  // Quote base4 = base2;
  // Quote base5 = std::move(base2);
  // base5 = std::move(base2);
  Bulk_quote derived1;
  Bulk_quote derived2("999-999", 10, 100, 0.1);
  // base5 = derived1;  // Quote copy assignment operator
  // Quote base;
  Quote *p;
  p = &derived1;
  print_total(cout, derived2, 100);
}
