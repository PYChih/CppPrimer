/*
- ==練習6.53==: 說明下列宣告組合中第二個宣告的效果。如果有的話，指出哪個是非法的
```
//a: 從對整數的參考變成對const int的參考
int calc(int&, int&);
int calc(const int&, const int&);
//b: 
int clac(char*, char*);
int calc(const char*, const char*);
//c://這個非法喔
int calc(char*, char*);
int calc(char* const, char* const);
```
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() 
{
}