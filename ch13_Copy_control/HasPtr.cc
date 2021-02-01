#include <utility>
#include "HasPtr.h"
using std::string;
inline
void swap(HasPtr &lhs, HasPtr &rhs) {
  using std::swap;
  swap(lhs.ps, rhs.ps);
  swap(lhs.i, rhs.i);
}
// copy and swap version copy and move assignment operator
// HasPtr& HasPtr::operator=(HasPtr rhs) {
//   swap(*this, rhs);
//   return *this;
// }
HasPtr& HasPtr::operator=(const HasPtr &rhs) {
  auto newp = new string(*rhs.ps);
  delete ps;
  ps = newp;
  i = rhs.i;
  return *this;
}
HasPtr& HasPtr::operator=(HasPtr &&rhs) noexcept {
  if (this != &rhs) {
    ps = rhs.ps;
    rhs.ps = nullptr;
  }
  return *this;
}