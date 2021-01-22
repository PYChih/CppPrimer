// Exercise 12.17:
//  Which of the following unique_ptr declarations are illegal or likely to
// result in subsequent program error? Explain what the problem is with each
// one.
#include <iostream>
#include <memory>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::make_shared;
using std::shared_ptr;
using std::unique_ptr;

int main()
{
    int ix = 1024, *pi = &ix, *pi2 = new int(2048);
    typedef unique_ptr<int> IntP;
    // a
    // IntP p0(ix); // illegal
    // b
    // IntP p1(pi); // Segmentation fault (core dumped) the object is not allocate using new.
    // c
    IntP p2(pi2); // dangling pointer at run time.
    // d
    // IntP p3(&ix); // not allocated using new.
    // e
    // IntP p4(new int(2048)); // Recommended
    // f
    // IntP p5(p2.get()); // double free
}
