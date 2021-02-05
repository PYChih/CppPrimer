// Exercise 14.38
// Write a class that tests whether the length
//  of a given string matches a given bound.
//  Use that object to write a program
//  to report how many words in an input
//  file are of sizes 1 through 10 inclusive.
#include <cstddef>
#include <iostream>
#include <string>
#include <fstream>
#include <map>
using std::string;
class IsInBound {
 public:
  IsInBound(std::size_t low, std::size_t upp) : _lower(low), _upper(upp) { }
  bool operator() (const string &s) const {
    return s.size() >= _lower && s.size() <= _upper;
  }
 private:
  std::size_t _lower = 1;
  std::size_t _upper = 10;
};
int main() {
  std::map<std::size_t, std::size_t> count_table;
  std::ifstream f("data/finding_cycle_start");
  string s;
  IsInBound iib(1, 10);
  while (f >> s) {
    // std::cout << s << std::endl;
    if (iib(s)) {
      ++count_table[1];
    }
  }
  // print
  for (auto p : count_table) {
    std::cout << "count in range [1, 10] : " << p.second << std::endl;
  }
}
