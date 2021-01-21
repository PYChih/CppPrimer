// Exercise 13_16
// What if the parameter in f were const numbered&?
// Does that change the output? If so, why? What output gets generated?
#include <iostream>
#include <string>
int num = 0;
class numbered {
friend void f(const numbered& s);
 public:
  numbered() { mysn = num++;}
  numbered(const numbered &s) { mysn = num++;}
 private:
  int mysn;
};
void f(const numbered& s) { std::cout << s.mysn << std::endl; }
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
