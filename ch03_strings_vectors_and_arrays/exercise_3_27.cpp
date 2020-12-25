// g++ exercise_3_27.cpp && ./a.out
/*
- 練習3.27: 假設txt_size是一個函式，他不接受引數(arguments)，並回傳一個int值，下列哪些定義是非法的？解釋原因。
```
unsigned buf_size = 1024;
a. int ia[buf_size];
b. int ia[4*7-14];
c. int ia[txt_size()];
d. char st[11] = "fundamental";
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
int rti(){
    int s = 0;
    return s;
}
int main(){
    unsigned buf_size = 1024;
    //int ia[buf_size];
    //int ia[4*7-14];
    int ia[rti()];
    char st[12] = "fundamental";
    return 0;
}