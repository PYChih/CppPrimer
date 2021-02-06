// Exercise 14.45
//  Write conversion operators to convert a Sales_data
//  to string and to double.
//  What values do you think these operators should return?
//  revenue and bookNo
// Sales_data_14_45.h and Sales_data_14_45.cc
// g++ -c Sales_data_14_45.cc exercise_14_45.cc
// g++ Sales_data_14_45.o exercise_14_45.o && ./a.out
#include "Sales_data_14_45.h"
using std::cout;
using std::endl;
using std::string;
int main() {
  Sales_data book1("0-201-70353-X", 4, 24.99);
  Sales_data book2("0-201-82470-1", 4, 45.39);
  Sales_data book3;
  // if (book3) {
  //   cout << "book3 2 bool is true" << endl;
  // }
  // cout << "book3 2 bool is false" << endl;
  cout << book3 << endl;
  string s = static_cast<string>(book2);
  cout << s << endl;
}