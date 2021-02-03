// Exercise 14.08
//  Define an output operator for the class you chose
//  in exercise 7.40 from 7.5.1 (p. 291).
// Book_14_08.h, Book_14_08.cc
// g++ -c Book_14_08.cc exercise_14_08.cc
// g++ Book_14_08.o exercise_14_08.o && ./a.out < data/book_sales
#include "Book_14_08.h"
using std::cin;
using std::cout;
using std::endl;
int main() {
  Book sd;
  while (read(cin, sd)) {
    cout << sd << endl;
  }
}
