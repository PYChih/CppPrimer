/*
- 練習5.24: 改寫你的程式，讓它在第二個數字是零的時候擲出一個例外。以一個零輸入測試你的程式，看看如果你不catch例外，在你的系統上會發生什麼事
## terminate called after throwing an instance of 'std::runtime_error'
g++ exercise_5_24.cpp && ./a.out
 */
#include<iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;


int main(){
    int int1, int2;
    cin>>int1>>int2;
    if (int2==0)
        throw runtime_error("can't devide by zero");
    cout<<static_cast<double>(int1)/int2<<endl;


    return 0;
}