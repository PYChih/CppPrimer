// Exercise 12.16:
//  Compilers don’t always give easy-to-understand error messages
//  if we attempt to copy or assign a unique_ptr.
//  Write a program that contains these errors
//  to see how your compiler diagnoses them.
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

int main() {
    unique_ptr<string> p1(new string("first unique_ptr"));
    cout << *p1 << endl;
    // unique_ptr<string> p2(p1); // let's try copy
    // error: use of deleted function
    // unique_ptr<string> p3 = p1;  // assign
    // error: use of deleted function
    // for correct copy
    unique_ptr<string> p2(p1.release());  // now p1 will be null
    cout << *p2 << endl;
    // for correct assign
    string* p3 = p2.release();  // now p2 will be null
    cout << *p3 << endl;
}
