// Exercise 10.15:
// Write a lambda that captures an int from its enclosing function and takes an int parameter. 
// The lambda should return the sum of the captured int and the int parameter.
#include<iostream>
using namespace std;

int main(){
    int s = 10;
    auto f = [s](int j) -> int {return s+j;};
    cout<<f(5)<<endl;
    return 0;
}