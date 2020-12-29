/*
- 練習6.41: 下列哪個呼叫是非法的呢? 為什麼呢? 如果有的話，哪個是合法的，但不太可能是程式設計師所期望的，為什麼呢?
```
char *init(int ht, int wd=80, char bckgrnd = ' ');
//a: 非法，ht要給值
init();
//b: ht給24, wd給80
init(24, 10);
//c: 合法，可是'*'會被轉成int然後給wd
init(14, '*')
```
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() 
{

}