// g++ exercise_4_29.cpp && ./a.out
/*
- 練習4.29: 預測下列程式碼並解釋你的推理。現在執行程式。輸出如你預期嗎? 如果不是，請找出原因。
```
int x[10];
int *p = x;
cout << sizeof(x)/sizeof(*x) << endl;
cout << sizeof(p)/sizeof(*p) << endl;
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
    int x[10];
    int *p = x;
    cout << sizeof(x)/sizeof(*x) << endl; // 10
    cout << sizeof(p)/sizeof(*p) << endl; // pointersize/intsize
    return 0;
}