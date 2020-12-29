/*
- 練習6.51: 寫出f的四個版本。每個函式都應該印出一個足以區別的訊息。檢查你在前一個練習的答案。如果你的答案是錯的，就研讀這一節，直到你了解為何答案是錯的為止。
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

void f(int i, int j){cout<<"int int"<<endl;}
void f(){cout<<"no param"<<endl;}
void f(double i, double j=3.14){cout<<"double double"<<endl;}
void f(int i){cout<<"int"<<endl;}

int main() 
{
    //f(2.56, 42);
    f();
    f(42);
    f(42, 0);
    f(2.56, 3.14);
}