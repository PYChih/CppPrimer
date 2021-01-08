// Exercise 10.14:
// Write a lambda that takes two ints and returns their sum.
#include<iostream>
using namespace std;


int main(){
    auto f = [](int i, int j) -> int {return i+j;};
    cout << f(1, 2) << endl;
    return 0;
}