// Exercise 14.15
//  Should the class you chose for exercise 7.40 from 7.5.1 (p. 291)
//  define any of the arithmetic operators?
//  If so, implement them. If not, explain why not.
// Book_14_15.h Book_14_15.cc
// g++ -c Book_14_15.cc exercise_14_15.cc
// g++ Book_14_15.o exercise_14_15.o && ./a.out < data/add_item
#include "Book_14_15.h"  // NOLINT
using std::cin;
using std::cout;
using std::endl;
int main() {
  Book b1, b2;
  cin >> b1 >> b2;
  cout << "book1 " << b1 << endl;
  cout << "book2 " << b2 << endl;
  cout << "sum " << b1 + b2 << endl;
}
