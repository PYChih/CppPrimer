// Exercise 13.22
//  Assume that we want HasPtr to behave like a value.
//  That is, each object should have its own copy of
//  the string to which the objects point.
//  We'll show the definitions of the copy-control
//  members in the next section.
//  However, you already know everything you need to
//  know to implement these members.
//  Write the HasPtr copy constructor and copyassignment
//  operator before reading on.
#include<iostream>
#include<memory>
#include<string>
class HasPtr {
 public:
  HasPtr(const std::string &s = std::string()):  // NOLINT
    ps(new std::string(s)), i(0) {}
  HasPtr(const HasPtr& hp):  // copy constructor
    ps(new std::string(*(hp.ps))), i(hp.i) {}
  HasPtr& operator=(HasPtr & hp) {  // NOLINT copy-assignment operator
    std::string *newps = new std::string(*hp.ps);
    delete ps;
    ps = newps;
    i = hp.i;
    return *this;
  }
  ~HasPtr() {
    delete ps;
  }

 private:
  std::string *ps;
  int i;
};

int main() {
  return 0;
}
