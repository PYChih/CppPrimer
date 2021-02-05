// Exercise_14_43
//  Using library function objects,
//  determine whether a given int value
//  is divisible by any element in a container of ints.
#include <functional>
#include <vector>
#include <algorithm>
#include <iostream>
using std::vector;
using std::modulus;
int main() {
  vector<int> ivec{2, 3, 5, 7, 11, 13, 17, 19};
  int targ_val = 34;
  auto divisible = [&targ_val](int i) {
    return 0 == modulus<int>()(targ_val, i);
  };
  auto is_divisible = std::any_of(ivec.begin(), ivec.end(), divisible);
  std::cout << is_divisible << std::endl;
}