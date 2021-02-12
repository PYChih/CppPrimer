// Exercise 15.28:
// Define a vector to hold Quote objects but put Bulk_quote objects into that
// vector. Compute the total net_price of all the elements in the vector.
// Quote_15_28.cc Quote_15_28.h
// g++ -c exercise_15_28.cc Quote_15_28.cc
// g++ exercise_15_28.o Quote_15_28.cc && ./a.out
#include <vector>
#include "Quote_15_28.h"
using std::vector;
using std::cout;
using std::endl;
int main() {
  Bulk_quote b1("999-999-999", 10, 10, 0.1);
  Quote q1("qqq-qqq-qqq", 99);
  cout << b1.net_price(10) << endl;
  cout << q1.net_price(10) << endl;
  Quote q2 = q1;
  vector<Quote> book_vec;
  book_vec.push_back(b1);
  book_vec.push_back(q1);
  double total = 0;
  for (auto book : book_vec) {
    total += book.net_price(20);
  }
  cout << "total : " << total << endl;
}