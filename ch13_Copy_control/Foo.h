#ifndef FOO_H_
#define FOO_H_
#include <vector>
#include <algorithm>
class Foo {
 public:
  Foo sorted() &&;  // sort on rvalue(we can change)
  Foo sorted() const &;  // can not change

 private:
  std::vector<int> data;
};
#endif  // FOO_H_
