//  Exercise_13_05
// Given the following sketch of a class,
// write a copy constructor that copies all the members.
// Your constructor should dynamically allocate a new string
// and copy the object to which ps points,
// rather than copying ps itself.
#include<iostream>
#include<memory>
#include<string>
class HasPtr {
 public:
  HasPtr(const std::string &s = std::string()):  // NOLINT
    ps(new std::string(s)), i(0) {}
  HasPtr(const HasPtr& hp):
    ps(new std::string(*(hp.ps))), i(hp.i) {}

 private:
  std::string *ps;
  int i;
};

int main() {
  return 0;
}
