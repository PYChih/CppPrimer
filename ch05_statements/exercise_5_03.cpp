//g++ exercise_5_03.cpp && ./a.out
/*
- 練習5.3:
使用逗號運算子改寫來自1.4.1的while迴圈，讓它不再需要一個區塊。解釋這種改寫方式增進或減少程式碼的可讀性
```
// 1.4.1的while迴圈
while (val <=10){
    sum += val;
    ++val;
}
 */
#include<iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(){
    int val=0, sum=0;
    while (val <=10)
        sum+=val, ++val;
    cout<< "while out "<<"val = "<<val<<endl;
    return 0;
}