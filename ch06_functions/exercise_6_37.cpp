/*
- 練習6.37: 為前一個練習中的函式撰寫三個額外的宣告。其中一個應該使用型別別名，一個使用尾端回傳，而第三個使用decltype。你喜歡哪個形式? 為什麼呢?
string (&returnReference(string &s))[10];
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//
//typedef string strArr[10];
//using strArr = string[10];
//strArr& returnReference(string &s);
//
//auto returnReference(string &s) -> string(&)[10];
//
string S[10];
decltype(S)& returnReference(string &s);
int main() 
{
    string s1[10];
}