// Exercise 14.35
//  Write a class like PrintString that reads a line of input from an istream
//  and returns a string representing what was read.
//  If the read fails, return the empty string.
#include "exercise_14_35.h"  // NOLINT
int main() {
  ReadString rs;
  std::string str;
  str = rs();
  std::cout << str;
  std::cout << std::endl;
}
