// g++ exercise_3_44.cpp && ./a.out
/*
- 練習3.43: 寫出三種不同版本的程式來印出ia的元素。一個版本使用範圍for來管理迭代動作(a)，一個使用下標(b)，一個使用指標(c)。並且禁止使用auto和decltype. 
練習3.44: 改寫前面的練習，使用一個型別別名作為迴圈控制變數的型別 
```
int ia[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
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
    int ia[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };
    using row_vector = int[4]; 
    for (row_vector &row : ia){
        for (int &i : row){
            cout<<i<<' ';
        }
        cout<<endl;
    }
    return 0;
}