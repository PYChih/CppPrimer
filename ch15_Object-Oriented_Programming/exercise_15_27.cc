// Exercise 15_27
//  Redefine your Bulk_quote class to inherit its constructors.
// Quote_15_27.cc Quote_15_27.h
// g++ -c exercise_15_27.cc Quote_15_27.cc
// g++ exercise_15_27.o Quote_15_27.cc && ./a.out
#include "Quote_15_27.h"
using std::cout;
using std::endl;
int main() {
  Bulk_quote derived1;
  Bulk_quote derived2("999-999", 10, 100, 0.1);
  // base5 = derived1;  // Quote copy assignment operator
  // Quote base;
  Quote *p;
  p = &derived1;
  print_total(cout, derived2, 100);
}
