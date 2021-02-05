// Exercise 14_37
//  Write a class that tests whether two values are equal.
//  Use that object and the library algorithms to write a program
//  to replace all instances of a given value in a sequence.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
class Realhiphop {
 public:
  Realhiphop() = default;
  bool operator()(std::string &s) {  // NOLINT
    if (s == gp) {
      return true;
    } else {
      return false;
    }
  }
 private:
  std::string gp = "grape";
};
int main() {
  Realhiphop rh;
  std::vector<std::string> eat{"Eating", "grape",
    "did", "not", "spit", "grape", "skins"};
  for (auto i : eat) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  std::replace_if(eat.begin(), eat.end(), rh, "Grapefruit");
  for (auto i : eat) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}
