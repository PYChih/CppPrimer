// Exercise 14.17
//  Should the class you chose for exercise 7.40 from 7.5.1(p. 291)
//  define the equality operators?
//  If so, implement them. If not, explain why not.
// Book_14_17.h Book_14_17.cc
// g++ -c Book_14_17.cc exercise_14_17.cc
// g++ Book_14_17.o exercise_14_17.o && ./a.out
#include "Book_14_17.h"
using std::cout;
using std::endl;
int main() {
  Book b1("aaa", 1, 1), b2("aaa", 1, 1), b3("aa", 1, 1);
  cout << "b1 == b2 ? " << (b1 == b2) << endl;
  cout << "b1 != b2 ? " << (b1 != b2) << endl;
}
