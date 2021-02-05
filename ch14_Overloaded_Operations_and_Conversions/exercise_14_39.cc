// Exercise 14.39
//  Revise the previous program to report the count
//  of words that are sizes 1 through 9 and 10 or more.
#include <cstddef>
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <iterator>
#include <vector>
#include <algorithm>
using std::vector;
using std::string;
using std::cout;
using std::endl;
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
class ShorterString {
 public:
  bool operator()(const string &s1, const string &s2) const {
    return s1.size() < s2.size();
  }
};
class SizeComp {
 public:
  SizeComp(size_t n): sz(n) { }  // NOLINT
  bool operator()(const string &s) const {
    return s.size() >= sz;
  }
 private:
  size_t sz;
};
int main() {
  std::map<std::size_t, std::size_t> count_table;
  std::ifstream f("data/finding_cycle_start");
  std::istream_iterator<string> iit(f), eof;
  vector<string> vector_file(iit, eof);
  stable_sort(vector_file.begin(), vector_file.end(), ShorterString());
  auto pre_it = vector_file.begin();
  count_table[0] = vector_file.end() - vector_file.begin();
  for (size_t i = 1; i <= 11; ++i) {
    auto greater_i_it = find_if(vector_file.begin(), vector_file.end(),
                              SizeComp(i));
    // number of words greater than size i
    auto accg = vector_file.end() - greater_i_it;
    // count_table[i] : number of words in range i-1, i
    count_table[i] = greater_i_it - pre_it;
  }
  // print
  for (size_t i = 1; i < 11; ++i) {
    std::cout << "count in range [" << i - 1
              << ", " << i << ") : "
              << count_table[i] << std::endl;
  }
}
