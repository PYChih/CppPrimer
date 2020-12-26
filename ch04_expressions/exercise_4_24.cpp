//g++ exercise_4_24.cpp && ./a.out
/*
- 練習4.24: 我們區分高分通過、通過和沒通過的程式仰賴條件運算子是右結合的這個事實。描述如果該運算子是左結合的，會如何進行估算。
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
    //int grade = 70;
    int grade = 60;
    string finalgrade1 = (grade<60)?"fail":"pass";
    cout<<"final grade 1 : "<<finalgrade1<<endl;
    string finalgrade2 = (grade >90) ? "high pass"
                                     : (grade < 60) ? "fail" : "pass";
    return 0;
}