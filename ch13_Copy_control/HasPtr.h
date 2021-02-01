#ifndef HASPTR_H_
#define HASPTR_H_
#include <string>
#include <memory>
#include <utility>
// value version
class HasPtr {
  friend void swap(HasPtr&, HasPtr&);
 public:
  HasPtr(const std::string &s = std::string()):  // NOLINT
    ps(new std::string(s)), i(0) { }
  HasPtr(const HasPtr &p):
    ps(new std::string(*p.ps)), i(p.i) { }  // copy constructor
  // HasPtr& operator=(HasPtr rhs);  // copy and swap
  ~HasPtr() { delete ps; }  // destructor
  // move constructor
  HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i) {p.ps = 0;}
  HasPtr& operator=(const HasPtr &rhs);  // copy assignment operator
  HasPtr& operator=(HasPtr &&rhs) noexcept;  // move assignment operator
 private:
  std::string *ps;
  int i;
};
#endif  // HASPTR_H_
