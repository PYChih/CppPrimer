// Exercise 13_15
// Assume numbered has a copy constructor that generates a new serial number.
// Does that change the output of the calls in the previous exercise?
// If so, why? What output gets generated?
#include <iostream>
#include <string>
int num = 0;
class numbered {
friend void f(numbered s);
 public:
  numbered():mysn(num) { num+=1;}
  numbered(numbered &s) : mysn(num) { num+=1;}
 private:
  int mysn;
};
void f(numbered s) { std::cout << s.mysn << std::endl; }
int main() {
  std::cout << "num : " << num << std::endl;
  numbered a, b = a, c = b;
  numbered d;
  std::cout << "num : " << num << std::endl;
  f(a);
  f(b);
  f(c);
  f(d);
  std::cout << "num : " << num << std::endl;
  f(a);
}
