//g++ exercise_4_37.cpp && ./a.out
/*
- 練習4.37: 使用具名的強制轉型改寫下列的舊式強制轉型:
```
int i; double d; const string *ps; char *pc; void *pv;
a. pv = (void*)ps;
b. i = int(*pc);
c. pv = &d;
d. pc = (char*) pv;
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
    int i; double d; const string *ps; char *pc; void *pv;
    //a
    //pv = (void*)ps;
    //pv = const_cast<string*>(ps);
    //b
    //i = int(*pc);
    //i = static_cast<int>(*pc);
    //c
    //pv = &d;
    pv = static_cast<void*>(&d);
    //d
    //pc = (char*) pv;
    pc = static_cast<char*> (pv);
    return 0;
}