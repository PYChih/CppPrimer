//  Exercise 12.26
//  Rewrite the program on page 481 using an allocator.
#include <iostream>
#include <string>
#include <memory>
using std::allocator;
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main() {
  int n = 10;
  // string *const p = new string[n]; // p is const and p is pointer
  // string s;
  // string *q = p;
  // while (cin >> s && q != p + n)
  //    *q++ = s;
  // const size_t size = q - p;
  // cout<<*p<<endl;
  // delete [] p;
  allocator<string> alloc;
  auto const p = alloc.allocate(n);
  string s;
  string *q = p;  // construct from q
  while (cin >> s && q != p+n) {
    alloc.construct(q, s);
    cout << "construct " << q-p << "th string : " << s << endl;
      ++q;
  }
  string *r = p;
  cout << "print current string array " << endl;
  while (r != q) {
    cout << *r << endl;
    ++r;
  }
  cout << "destroy string array " << endl;
  while (q != p) {
    --q;
    cout << *q << endl;
    alloc.destroy(q);
  }
    return 0;
}
