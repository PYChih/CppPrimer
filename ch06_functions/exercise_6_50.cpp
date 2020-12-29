/*
```
void f();
void f(int);
void f(int, int);
void f(double, double = 3.14);
f(5.6); // 呼叫void f(double, double)
```
- 練習6.50: 給定前面的f宣告，為下列每個呼叫列出合用的函式。指出哪個函式是最佳匹配，哪個呼叫因為沒有匹配或歧異而是非法的。
```
//a
f(2.56, 42)//這個有歧異
//b
f(42): f(int)
//c
f(42, 0) : f(int, int)
//d
f(2.56, 3.14) : f(double, double)
```
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() 
{

}