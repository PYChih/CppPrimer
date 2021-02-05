// Exercise 14.42
//  Using library function objects and adaptors, define an expression to
//  (a) Count the number of values that are greater than 1024
//  (b) Find the first string that is not equal to pooh
//  (c) Multiply all values by 2
#include <functional>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using std::string;
using std::vector;
using std::less;
using std::greater;
using std::not_equal_to;
using std::multiplies;
using namespace std::placeholders;  // NOLINT
using std::cout;
using std::endl;
int main() {
  vector<int> ivec, multiply_vec;
  for (auto i = 0; i < 2048; ++i) {
    ivec.push_back(i);  // 0~2047
  }
  for (auto i = 0; i < 6; ++i) {
    multiply_vec.push_back(i);
  }
  vector<string> svec{"pooh", "pooh", "pooh", "ooh"};
  // a
  int num = std::count_if(ivec.begin(), ivec.end(),
                          std::bind(greater<int>(), _1, 1024));
  cout << "there are " << num << " of ints greater than 1024" << endl;
  // b
  auto it = std::find_if(svec.begin(), svec.end(),
                         std::bind(not_equal_to<string>(), _1, string("pooh")));
  cout << *it << endl;
  // c
  std::transform(multiply_vec.begin(), multiply_vec.end(),
                 multiply_vec.begin(),
                std::bind(multiplies<int>(), _1, 2));
  for (auto i : multiply_vec) {
    cout << i << " ";
  }
  cout << endl;
}