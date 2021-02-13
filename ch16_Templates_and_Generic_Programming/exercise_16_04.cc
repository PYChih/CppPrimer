// Exercise 16.4:
// Write a template that acts like the library find algorithm. The function
// will need two template type parameters, one to represent the function’s
// iterator parameters and the other for the type of the value. Use your
// function to find a given value in a vector<int> and in a list<string>.
#include <iostream>
#include <vector>
#include <list>
#include <string>
using std::vector;
using std::string;
using std::list;
using std::cout;
using std::endl;
template<typename Iterator, typename Value>
auto self_find(Iterator beg, Iterator end, Value const &val) {
  while (beg != end) {
    if (*beg == val) {
      return beg;
    }
    ++beg;
  }
  return beg;
}
int main() {
  vector<int> ivec{1, 2, 3, 4, 5};
  list<string> ilist{"hello", "World"};
  int val1 = 1;
  int val2 = 6;
  string str1 = "hello";
  string str2 = "Hello";
  auto it = self_find(ivec.begin(), ivec.end(), val1);
  if (it != ivec.end()) {
    cout << "find " << val1 << "," << *it << endl;
  } else {
    cout << val1 << "no find" << endl;
  }
  auto sit = self_find(ilist.begin(), ilist.end(), str1);
  if (sit != ilist.end()) {
    cout << "find " << str1 << "," << *sit << endl;
  } else {
    cout << str1 << "no find" << endl;
  }
}