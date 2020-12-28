/*
- 練習5.23: 寫一個程式從標準輸入讀取兩個整數，並印出第一個數字除以第二個的結果。
g++ exercise_5_23.cpp && ./a.out
 */
#include<iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;


int main(){
    int int1, int2;
    cin>>int1>>int2;
    if (int2>0){
    cout<<static_cast<double>(int1)/int2<<endl;
    } else{
        cout<<" can't / 0"<<endl;
        return -1;
    }

    return 0;
}