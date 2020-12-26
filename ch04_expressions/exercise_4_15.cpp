//g++ exercise_4_15.cpp && ./a.out
/*
- 練習4.15: 下列的指定是非法的。為什麼呢? 你要如何更正它們?
```
double dval; int ival; int *pi;
dval = ival = pi = 0;
```
 */
#include<iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(){
    double dval; int ival; int *pi;
    dval = ival = *pi = 0;
    cout<< "*pi: "<<*pi<<endl;
    cout<<"ival: "<<ival<<endl;
    cout<<"dval: "<<dval<<endl;
    return 0;
}
