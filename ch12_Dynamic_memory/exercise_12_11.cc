// Exercise 12.11:
//  What would happen if we called process as follows?
//  process(shared_ptr<int>(p.get()));
//   inside the process function:1
//   free(): double free detected in tcache 2
//   Aborted (core dumped)
#include <iostream>
#include <memory>
using std::cin;
using std::cout;
using std::endl;
void process(std::shared_ptr<int> ptr) {
    cout << "inside the process function: "
         << ptr.use_count() << endl;
}
int main() {
    // use new to initialize the shared_ptr p
    std::shared_ptr<int> p(new int(42));
    cout << "count after initial" << p.use_count() << endl;
    process(std::shared_ptr<int>(p));
    cout << "after call function " << p.use_count() << endl;
    // process(std::shared_ptr<int>(p.get()));
}