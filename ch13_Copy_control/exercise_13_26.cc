//  Exercise 13.26
//  Write your own version of the StrBlob class
//  described in the previous exercise.
#include <iostream>
#include <string>
#include <vector>
#include "exercise_13_26.h" //NOLINT
using std::vector;
using std::string;
using std::cout;
using std::endl;
int main() {
    StrBlob b1{"a", "an", "the"};
    vector<string> str_vec = *b1.get_data();
    StrBlob b2 = b1, b3;
    b3 = b1;
    // here b1 and b2 and b3 use same dynamic allocate
    // vector<string> therefore use_count should be 3
    cout << b1.get_count() << endl;
    cout << b2.get_count() << endl;
    cout << b3.get_count() << endl;
    return 0;
}
