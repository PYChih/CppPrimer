/*
- 練習6.36: 宣告一個會回傳一個參考的函式，該參考指涉有十個string的一個陣列，而且不使用尾端回傳、decltype或型別別名。
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;
string (&returnReference(string &s))[10];
int main() 
{
    string s1[10];
}