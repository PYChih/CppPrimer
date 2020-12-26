//g++ exercise_4_13.cpp && ./a.out
/*
- 練習4.13: 每個指定後的i和d各是什麼?
``int i; double d;``
a. ``d = i = 3.5;``指定的時候會把右邊的型別指定給左邊，所以i會變成3然後d就會是3
b. ``i = d = 3.5;``d是3.5然後i是3
 */
#include<iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(){
    int i;
    double d;
    //d = i = 3.5;
    i = d = 3.5;
    return 0;
}
