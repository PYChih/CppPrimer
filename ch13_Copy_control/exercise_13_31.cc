// Exercise 13.30
//  Write and test a swap function
//  for your valuelike version of HasPtr.
//  Give your swap a print statement that
//  notes when it is executed.
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
class HasPtr {
 public:
  friend void swap(HasPtr& hp1, HasPtr& hp2);
  HasPtr(const std::string &s = std::string()):  // NOLINT
    ps(new std::string(s)), i(0) {}
  HasPtr(const HasPtr& hp):  // copy constructor
    ps(new std::string(*(hp.ps))), i(hp.i) {}
//  HasPtr& operator=(HasPtr & hp) {  // NOLINT copy-assignment operator
//    std::string *newps = new std::string(*hp.ps);
//    delete ps;
//    ps = newps;
//    i = hp.i;
//    return *this;
//  }
  HasPtr& operator=(HasPtr hp) { // NOLINT note that param pass by value
    swap(*this, hp);
    return *this;
  }
  bool operator<(HasPtr hp) { return *ps < *hp.ps; }
  ~HasPtr() {
    delete ps;
  }

 private:
  std::string *ps;
  int i;
};
inline
void swap(HasPtr &hp1, HasPtr &hp2) {
    std::cout << "I'm swapping !!" << std::endl;
    using std::swap;
    swap(hp1.ps, hp2.ps);
    swap(hp1.i, hp2.i);
}
int main() {
  HasPtr hp1{"I'm hp1"}, hp2{"I'm hp2"}, hp3;
  std::cout << ("I'm hp1" < "I'm hp2") << std::endl;
  std::cout << (hp1 < hp2) << std::endl;
  swap(hp1, hp2);
  hp3 = hp2;
  std::vector<HasPtr> hpvec{HasPtr("3"), HasPtr("1"), HasPtr("2"), HasPtr("4")};
  std::sort(hpvec.begin(), hpvec.end());
  return 0;
}
