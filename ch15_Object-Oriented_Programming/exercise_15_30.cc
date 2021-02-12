// Exercise 15.30
//  Write your own version of the Basket class
//  and use it to compute prices for the same transactions
//  as you used in the previous exercises.
// Basket_15_30.cc Basket_15_30.h
// Quote_15_30.cc Quote_15_30.h
// g++ -c exercise_15_30.cc Quote_15_30.cc Basket_15_30.cc
// g++ exercise_15_30.o Quote_15_30.o Basket_15_30.o && ./a.out
#include "Basket_15_30.h"
int main() {
  Bulk_quote b1("999-999-999", 10, 10, 0.1);
  Quote q1("qqq-qqq-qqq", 99);
  // print_total(std::cout, q1, 10);
  // print_total(std::cout, b1, 10);
  Basket bk;
  for (auto i = 0; i < 10; ++i) {
    bk.add_item(b1);
    bk.add_item(q1);
  }
  bk.total_receipt(std::cout);
}