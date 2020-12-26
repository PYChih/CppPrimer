//g++ exercise_4_22.cpp && ./a.out
/*
- 練習4.22: 擴充會指定高分通過、通過或沒通過的程式，讓它也會為介於60和75之間(包括兩端)的成績指定低分通過(low pass)。撰寫兩個版本: 一個只使用條件運算子，另一個應該使用一或更多個if述句。你認為哪個版本比較容易理解?為什麼呢?
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
    cout<<"final grade 2 : "<<finalgrade2<<endl;
    string finalgrade3 = (grade >90) ? "high pass"
                                     : (grade > 75) ? "pass" 
                                                    : (grade < 60)? "fail" : "low pass";
    cout<<"final grade 3 : "<<finalgrade3<<endl;
    return 0;
}