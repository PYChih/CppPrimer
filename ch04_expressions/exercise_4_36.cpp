//g++ exercise_4_36.cpp && ./a.out
/*
- 練習4.36: 假設i是一個int而d是一個double，請寫出運算式i *= d，讓它進行整數的，而非浮點數的乘法運算
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
    int i = 2;
    double d = 3.14;
    double c;
    c = i* static_cast<int>(d);
    cout<<c<<endl;

    return 0;
}