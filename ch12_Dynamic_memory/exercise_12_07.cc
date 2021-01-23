// Exercise 12.7:
// Redo the previous exercise, this time using shared_ptr.
//   Exercise 12.6:
//   Write a function that returns a dynamically allocated vector of ints.
//   Pass that vector to another function that reads the standard input to
//   give values to the elements. Pass the vector to another function to print
//   the values that were read.
//   Remember to delete the vector at the appropriate time.
#include <iostream>
#include <vector>
#include <memory>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::make_shared;
using std::shared_ptr;
shared_ptr<vector<int>> dy_alloc_intv() {
    // vector<int>* ivec_ptr = new vector<int>{};
    return make_shared<vector<int>>();
}
void assign_value(shared_ptr<vector<int>> ivec_ptr) {
    int i;
    while (cin >> i) {
        ivec_ptr->push_back(i);
    }
}
void print_ivec(shared_ptr<vector<int>> ivec_ptr) {
    for (auto i : *ivec_ptr) {
        cout << i << endl;
    }
}
int main() {
    shared_ptr<vector<int>> dynamic_ivecptr = dy_alloc_intv();
    cout << dynamic_ivecptr->size() << endl;
    assign_value(dynamic_ivecptr);
    print_ivec(dynamic_ivecptr);
    return 0;
}
