// Exercise 12.23
//  Write a program to concatenate two string literals,
//  putting the result in a dynamically allocated array of char.
//  Write a program to concatenate two library strings that have
//  the same value as the literals used in the first program.
#include <iostream>
#include <string>
#include <memory>
#include <cstring>
using std::strlen;
using std::strcat;
using std::strcpy;
using std::unique_ptr;
using std::cout;
using std::endl;
using std::string;
int main() {
  char c_s1[] = "Hello";
  char c_s2[] = "World";
  unique_ptr<char[]> dyn_char(new char[strlen(c_s1)+strlen(c_s2)+1]);
  for (int i = 0; i < strlen(c_s1); ++i) {
    dyn_char[i] = c_s1[i];
  }
  for (int i = 0; i < strlen(c_s2); ++i) {
    dyn_char[i+5] = c_s2[i];
  }
  for (int i = 0; i < strlen(c_s1)+strlen(c_s2) + 1; ++i) {
      cout << dyn_char[i] << " ";
  }
  cout << endl;
  string str_s1("Hello");
  string str_s2("World");
  string s3 = str_s1 + str_s2;
  unique_ptr<char[]> dyn_char2(new char[s3.size()+1]);
  for (int i = 0; i < s3.size(); ++i) {
    dyn_char2[i] = s3[i];
  }
  for (int i = 0; i < strlen(c_s1) + strlen(c_s2) + 1; ++i) {
    cout << dyn_char2[i] << " ";
  }
  cout << endl;
  dyn_char.reset();
  dyn_char2.reset();
  return 0;
}
