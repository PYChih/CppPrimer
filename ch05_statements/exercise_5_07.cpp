//g++ exercise_5_07.cpp && ./a.out
/*
- 練習5.7: 更正列下列各個程式碼片段中的錯誤:
```
\\a
if (ival1 != ival2)
    ival1 = ival2
else ival1=ival2=0;
\\b
if (ival1 < minval)
    minval = ival1;
    occurs = 1;
\\c
if (int ival = get_value())
    cout<< "ival = " << ival << endl;
if (!ival)
    cout<< "ival = 0\n";
\\d
if (ival = 0)
    ival = get_value();
```
 */
#include<iostream>
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(){
    int ival1 = 10, ival2 = 30, minval = 5, occurs=0;
    //a
    if (ival1 != ival2)
        ival1 = ival2;
    else ival1=ival2=0;
    //b
    if (ival1 < minval)
        minval = ival1, occurs = 1;
    //c
    //if (int ival = get_value())
    //    cout<< "ival = " << ival << endl;
    if (!ival1)
        cout<< "ival = 0\n";
    //d
    //if (ival1 == 0)
    //    ival1 = get_value();
    return 0;
}