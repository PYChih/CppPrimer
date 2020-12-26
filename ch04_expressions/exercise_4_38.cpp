//g++ exercise_4_38.cpp && ./a.out
/*
- 練習4.38: 解釋下列運算式:
``double slop = static_cast<double>(j/i);``
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
    int i = 3;
    int j = 1;
    cout<<j/i<<endl;
    cout<<static_cast<double>(j)/i<<endl;
    cout<<static_cast<double>(j/i)<<endl;


    return 0;
}