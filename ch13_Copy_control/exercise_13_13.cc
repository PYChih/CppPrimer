// Exercise 13_13
//  A good way to understand copy-control members and constructors
//  is to define a simple class with these members
//  in which each member prints its name:
//  struct X {
//    X() { std::cout << "X()" << std::endl; }
//    // copy constructure
//    X(const X&) { std::cout << "X(const X&)" << std::endl; }
//  };
//  Add the copy-assignment operator
//  and destructor to X and write a program using X objects in various ways:
//  Pass them as nonreference and reference parameters;
//  dynamically allocate them;
//  put them in containers; and so forth.
//  Study the output until you are certain you understand
//  when and why each copy-control member is used.
//  As you read the output, remember that
//  the compiler can omit calls to the copy constructor.
#include <iostream>
#include <vector>
#include <initializer_list>

struct X {
    X() { std::cout << "I'm default constructure" << std::endl; }
    X(const X&) { std::cout << "I'm copy constructure" << std::endl; }
    X& operator=(const X&) { std::cout << "I'm copy assign constructure"
                                       << std::endl;
                                       return *this; }
    ~X() { std::cout << "I'm destructor" << std::endl; }
};

void f(const X &rx, X x) {
    std::cout << "in the function" << std::endl;
    std::vector<X> vec;
    std::cout << "vector start!!" << std::endl;
    vec.push_back(x);
    vec.push_back(x);
}

int main() {
    X x, y;
    // x = y;
    // X z = x;
    f(x, y);
    std::cout << "out the function " << std::endl;
    return 0;
}
