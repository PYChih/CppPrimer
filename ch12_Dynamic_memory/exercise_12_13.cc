// Exercise 12.13:
//  What happens if we excute the following code?
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
    auto sp = make_shared<int> ();
    auto p = sp.get();  // now p is plain pointer
    cout << sp.use_count() << endl;
    delete p;  // double free
}
