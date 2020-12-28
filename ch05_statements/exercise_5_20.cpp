/*
- 練習5.20: 寫一個程式從標準輸入讀取一序列的string，值到相同的字詞(word)連續出現兩次，
或所有的字都已讀完為止。使用一個while迴圈從文字輸入一次讀取一個字。使用break述句在某個字連續出現兩次時，終結迴圈。如果是出現兩次，就印出那個字，不然就印出一個訊息指出沒有重複的字。
g++ exercise_5_20.cpp && ./a.out
 */
#include<iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int main(){
    cout << "Enter a sequence of string"<<endl;
    string str, prestr;
    int twotime=0;
    while(cin>>str){
        if (prestr==str){
            twotime=1;
            break;
        }
        prestr = str;
    }
    if (twotime==1){
        cout<<str<<" two times"<<endl;
    } else{
        cout<< "no word two times"<<endl;
    }
    return 0;
}