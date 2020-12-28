/*
- 練習5.16: 
while迴圈特別適合用於某個條件成立時就要重複執行的工作，例如當我們需要不斷讀取值，值到檔案結尾為止的時候。
for迴圈一般被想成是一種逐步迴圈: 藉由一個索引逐步處理過某個群集中一整個範圍的值。
以這兩個迴圈各自的習慣用法寫出兩個程式使用它們，然後改以另一個迴圈構造改寫這兩個程式。
如果你只能使用一種迴圈，你會選哪個?為什麼呢
g++ exercise_5_16.cpp && ./a.out
 */
#include<iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int main(){
    string str1;
    //while(cin>>str1){
    //    cout<<str1<<endl;
    //}
    vector<int> ivec{1, 2, 3, 4, 5};
    for(int i : ivec){
        cout<<i<<endl;
    }
    for (;cin>>str1;){
        cout<<str1<<endl;
    }
    int index=0;
    auto isize = ivec.size();
    while (index<isize){
        cout<<ivec[index]<<endl;
        ++index;
    }
    return 0;
}