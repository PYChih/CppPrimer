/*
- 練習6.17:寫一個函式來判斷一個string是否含有任何大寫字母。寫一個函式來將一個string全都變為小寫。你在這些函式中使用的參數有相同的型別嗎? 若是，為什麼呢?若非，為何沒有。//判斷不需要改動，改為小寫需要改動
 */
#include<iostream>
#include <string>

using namespace std;

bool isUpperFirst(const string &s)
{
    return isupper(s[0]);
}

void toLower(string &s)
{
    for (auto &ch : s){
        ch = tolower(ch);
    }
}

int main(){
    string s1{"Hello"}, s2{"HELLO"};
    cout<<"s1 "<<isUpperFirst(s1)<<endl;
    toLower(s2);
    cout<<"s2 "<<s2<<endl;
    return 0;
}