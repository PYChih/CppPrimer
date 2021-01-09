// Exercise 10.21:
// Write a lambda that captures a local int variable and decrements that variable until
// it reaches 0. Once the variable is 0 additional calls should no longer decrement the
// variable. The lambda should return a bool that indicates whether the captured variable is 0.

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int v=2;
    auto f = [&v]()->int{
        if (v>0){return --v;} 
        else{return 0;}};
    cout<<f()<<endl;

    return 0;
}