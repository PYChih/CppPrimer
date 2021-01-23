// Exercise 12.12:
//  Using the declarations of p and sp
//  explain each of the following calls to process.
//  If the call is legal, explain what it does.
//  If the call is illegal, explain why:
#include <iostream>
#include <memory>
using std::cin;
using std::cout;
using std::endl;
using std::make_shared;
using std::shared_ptr;
void process(std::shared_ptr<int> ptr) {
    cout << "inside the process function: "
         << ptr.use_count() << endl;
}
int main() {
    auto p = new int();
    auto sp = make_shared<int> ();
    // a
    process(sp);  // just copy sp which is shared_ptr to process().
    cout << "sp count : " << sp.use_count() << endl;
    // b
    // process(new int());
    // new int() will return a ptr, can't convert to smart pointer implicitly.
    // c
    // process(p); // same as b
    // d
    process(shared_ptr<int>(p));  // bad pratice
}
