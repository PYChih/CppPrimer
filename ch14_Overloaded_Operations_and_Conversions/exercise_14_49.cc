// Exercise_14_49
//  Regardless of whether it is a good idea to do so,
//  define a conversion to bool for the class from the previous exercise.
//   Exercise_14_48
//    Determine whether the class you used in exercise 7.40 from 7.5.1 (p. 291)
//    should have a conversion to bool.
//    If so, explain why, and explain whether the operator should be explicit.
//    If not, explain why not.
// Book_14_49.h Book_14_49.cc
// g++ -c exercise_14_49.cc Book_14_49.cc
// g++ exercise_14_49.o Book_14_49.o && ./a.out
#include <iostream>
using std::endl;
using std::cout;
#include "Book_14_49.h"
int main() {
  Book b1, b2("0-201-70353-X", 4, 24.99);
  if (b1) {
    cout << "b1 is true" << endl;
  } else {
    cout << "b1 is false" << endl;
  }
  if (b2) {
    cout << "b2 is true" << endl;
  } else {
    cout << "b2 is false" << endl;
  }
}