/*
- 練習6.11: 撰寫並測試接受一個參考的你自己版本的reset。//reset是一個把傳入的參數設為0的函數
 */
#include<iostream>
#include <string>

using namespace std;

void reset(int &i)
{
    i = 0;
}

int main(){
    int ival=1;
    reset(ival);
    cout<<"ival : "<<ival<<endl;
    return 0;
}