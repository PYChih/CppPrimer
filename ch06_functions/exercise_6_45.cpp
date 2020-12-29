/*
- 練習6.45: 重新檢視你為前面的練習所寫的程式，判斷它們是否應該被定義為inline。如果是，就那麼做。若非，請解釋它們為何不應該是inline。
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

inline bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

int main() 
{
    string s1="www", s2="wwww";
    cout<<isShorter(s1, s2)<<endl;
}