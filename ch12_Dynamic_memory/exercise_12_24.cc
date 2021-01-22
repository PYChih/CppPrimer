// Exercise 12.24
//  Write a program that reads a string from the
//  standard input into a dynamically allocated character array.
//  Describe how your program handles varying size inputs.
//  Test your program by giving it a string of data
//  that is longer than the array size you've allocated.
#include <iostream>
#include <string>
#include <memory>
#include <sstream>
using std::allocator;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::istringstream;
int main() {
  // allocate a character array with size n
  int n = 10;
  char *p = new char[n];
  auto q = p;
  string s;
  char c;
  int current_char_cnt = 0;
  while (cin >> s) {
    istringstream record(s);
    while (record >> c) {
      cout << "record loop " << endl;
      if (current_char_cnt <= n) {
        *q++ = c;
        ++current_char_cnt;
      } else {
          n *= 2;
          cout << "allocate n = " << n << endl;
          s = string(p, q);
          q = nullptr;
          delete [] p;
          p = new char[n];
          q = p;
          for (auto i : s) {
            *q++ = i;
          }
          *q++ = c;
          ++current_char_cnt;
        }
    }
  }
  cout << "total capacity : " << n << endl;
  cout << "used char : " << current_char_cnt << endl;
  char *r = p;
  while (r != q) {
    cout << *r++ << " ";
  }
  cout << endl;
  r = nullptr;
  q = nullptr;
  delete [] p;
  p = nullptr;

    return 0;
}

