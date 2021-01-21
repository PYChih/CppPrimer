// Exercise 13_14
// Assume that numbered is a class with a default constructor
// that generates a unique serial number for each object,
// which is stored in a data member named mysn.
// Assuming numbered uses the synthesized copy-control members
// and given the following function:
// void f (numbered s) { cout << s.mysn << endl; }
// what output does the following code product?
// numbered a, b = a, c=b;
// f(a); f(b); f(c);
#include <iostream>
#include <string>
int num = 0;
class numbered {
friend void f(numbered s);
 public:
  numbered():mysn(num) { num+=1;}
 private:
  int mysn;
};
void f(numbered s) { std::cout << s.mysn << std::endl; }
int main() {
  numbered a, b = a, c = b;
  numbered d;
  f(a);
  f(b);
  f(c);
  f(d);
}
