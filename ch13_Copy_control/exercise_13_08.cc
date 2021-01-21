// Exercise 13_08
//  Write the assignment operator for the HasPtr class
//  from exercise 13.5 in 13.1.1 (p. 499).
//  As with the copy constructor,
//  your assignment operator should copy the object to which ps points.
//    Exercise_13_05
//    Given the following sketch of a class,
//    write a copy constructor that copies all the members.
//    Your constructor should dynamically allocate a new string
//    and copy the object to which ps points,
//    rather than copying ps itself.
#include<iostream>
#include<memory>
#include<string>
class HasPtr {
 public:
  HasPtr(const std::string &s = std::string()):  // NOLINT
    ps(new std::string(s)), i(0) {}
  HasPtr(const HasPtr& hp):  // copy constructor
    ps(new std::string(*(hp.ps))), i(hp.i) {}
  HasPtr& operator=(HasPtr & hp) {  // NOLINT
    std::string *newps = new std::string(*hp.ps);
    delete ps;
    ps = newps;
    i = hp.i;
    return *this;
  }

 private:
  std::string *ps;
  int i;
};

int main() {
  return 0;
}
