// Exercise 14.12
//  Define an input operator for the class
//  you used in exercise 7.40 from 7.5.1 (p. 291).
//  Be sure the operator handles input errors.
// Book_14_12.h Book_14_12.cc
// g++ -c Book_14_12.cc exercise_14_12.cc
// g++ Book_14_12.o exercise_14_12.o && ./a.out < data/book_sales
#include "Book_14_12.h"  // NOLINT
using std::cin;
using std::cout;
using std::endl;
int main() {
  Book sd;
  while (cin >> sd) {
    cout << sd << endl;
  }
}
