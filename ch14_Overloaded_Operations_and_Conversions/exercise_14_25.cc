// Exercise 14.25
//  Implement any other assignment operators
//  your class should define. Explain which types
//  should be used as operands and why.
// Book_14_25.h Book_14_25.cc
// g++ -c Book_14_25.cc exercise_14_25.cc
// g++ Book_14_25.o exercise_14_25.o && ./a.out
#include "Book_14_25.h"
using std::cout;
using std::endl;
using std::string;
int main() {
  // test default constructor
  Book b1;
  // test single string constructor
  string s1 = "single_string_constructor";
  Book b2(s1);
  // no explicit
  Book b3("single_string_constructor2");
  // test three param constructor
  Book b4("1-1-1", 1, 1);
  // test copy constructor
  Book b5 = b4;
  // test copy assignment operator
  b5 = b3;
  // test move constructor
  Book bdontuse("n-n-n", 0, 0);
  Book b6 = std::move(bdontuse);
  // test move-assignment operator
  b6 = std::move(b6);
  // test == and !=
  cout << "== and !=" << endl;
  cout << (b1 == b2) << (b1 != b2) << endl;
  // test + and +=
  Book b7("9-9-9", 9, 9), b8("9-9-9", 1, 1);
  b7 += b8;
  // test <<
  cout << b7 << endl;
}
