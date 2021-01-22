#ifndef CH13_COPY_CONTROL_EXERCISE_13_27_H_
#define CH13_COPY_CONTROL_EXERCISE_13_27_H_
#include<iostream>
#include<memory>
#include<string>
class HasPtr {
 public:
  HasPtr(const std::string &s = std::string()):  // NOLINT
    ps(new std::string(s)), i(0), use(new int(1)) {}
  HasPtr(const HasPtr& hp):  // copy constructor
    ps(hp.ps), i(hp.i), use(hp.use) { ++*use; }
  HasPtr& operator=(HasPtr & hp) {  // NOLINT copy-assignment operator
    ++*hp.use;
    if (--*use == 0) {
        delete ps;
        delete use;
    }
    ps = hp.ps;
    i = hp.i;
    use = hp.use;
    return *this;
  }
  int print_count() { return *use; }
  ~HasPtr() {
    if (--*use == 0) {
        delete ps;
        delete use;
    }
  }

 private:
  std::string *ps;
  int i;
  int *use;
};

#endif  // CH13_COPY_CONTROL_EXERCISE_13_27_H_
