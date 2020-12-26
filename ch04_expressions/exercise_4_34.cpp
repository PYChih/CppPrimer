//g++ exercise_4_34.cpp && ./a.out
/*
- 練習4.34: 給定本節中的變數定義，解釋下列運算式會發生何種轉換:
```
a. if (fval) // float to bool
b. dval = fval + ival; // ival to float and fval + ival and to double
c. dval + ival * cval; // char to int and int times int and to double and add double.
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
    bool flag; char cval;
    short sval; unsigned short usval;
    int ival; unsigned int uival;
    long lval; unsigned long ulval;
    float fval; double dval;

    return 0;
}