// Exercise 14.44:
//  Write your own version of a simple desk calculator
//  that can handle binary operations.
#include <iostream>
#include <string>
#include <map>
#include <functional>
int add(int i, int j) { return i + j; }
auto mod = [](int i, int j) { return i % j; };
struct divide {
  int operator()(int denominator, int divisor) {
    return denominator / divisor;
  }
};

auto binops = std::map<std::string, std::function<int(int, int)>> {
  { "+", add },
  { "-", std::minus<int>()},
  { "/", divide()},
  { "*", [](int i, int j) { return i * j; }},
  {"%", mod}
};
int main() {
  while (std::cout << "enter as: num operator num :", true) {
    int lhs, rhs;
    std::string op;
    std::cin >> lhs >> op >> rhs;
    std::cout << binops[op](lhs, rhs) << std::endl;
  }
}
