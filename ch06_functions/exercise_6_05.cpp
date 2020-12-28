/*
- 練習6.5:
撰寫一個函式回傳其引數的絕對值(absolute value)。
g++ exercise_6_05.cpp && ./a.out
 */
#include<iostream>
#include <string>
using namespace std;


double abs(double val)
{
    if (val <0){
        val = -val;
    }
    return val;
}

int main(){
    double j;
    cout << "enter a number "<<endl;
    while (cin >> j){
        cout<< "abs("<<j<<") is "<<abs(j)<<endl;
    }
    return 0;
}