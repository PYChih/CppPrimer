/*
- 練習6.34: 如果factorial中的停止條件是if (val !=0) 會發生什麼事? 
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int factorial(int val)
{
    if (val>1)
        return factorial(val-1)*val;
    return 1;
}

int main() 
{
    factorial(10);
    cout<<factorial(10)<<endl;

}