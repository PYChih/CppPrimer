//g++ exercise_4_34.cpp && ./a.out
/*
- 練習4.35: 給定下列定義
```
char cval;
int ival;
unsigned int ui;
float fval;
double dval;
辨識出隱含的型別轉換，如果有的話:
a. cval = 'a' + 3; // char to int and int add int and to char
b. fval = ui - ival * 1.0; // ival 2 double times 1.0 and ui to double , double - double and to float 
c. dval = ui * fval; unsigned int to float and times float, convert to double and give to dval.
d. cval = ival + fval + dval; ival to float float add float to double add double and convert to char
```
 */
#include<iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main(){
    char cval;
    int ival;
    unsigned int ui;
    float fval;
    double dval;
    return 0;
}