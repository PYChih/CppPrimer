// g++ exercise_3_27.cpp && ./a.out
/*
- 練習3.28: 下列陣列中的值是什麼?
    - 定義在局部和全局的差別:
    - string本來就接受無參數初始化，所以每個都空字串
    - 全局的array初始化全都是0
    - 局部的array初始化是未定義
```
string sa[10]; // 10 個空字串
int ia[10];// 10個0
int main(){
    string sa2[10]; // 10個空字串
    int ia2[10]; // 10個0
}
```
 */
#include<iostream>
#include <string>
#include <vector>
#include <cctype>
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main(){
    return 0;
}