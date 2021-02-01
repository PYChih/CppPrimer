#include <algorithm>
#include <iostream>
#include "Foo.h"
using std::vector;
using std::sort;
using std::cout;
using std::endl;
Foo Foo::sorted() && {
  cout << "i'm change version" << endl;
  sort(data.begin(), data.end());
  return *this;
}
// Foo Foo::sorted() const & {
//   cout << "i'm no change version" << endl;
//   Foo ret(*this);
//   sort(ret.data.begin(), ret.data.end());
//   return ret;
// }
Foo Foo::sorted() const & {
  cout << "i'm no change version" << endl;
  return Foo(*this).sorted();
}
// Foo Foo::sorted() const & {
//   Foo ret(*this);
//   return ret.sorted();
// }