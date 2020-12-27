//g++ exercise_5_05.cpp && ./a.out
/*
- 練習5.5: 使用一個if-else述句寫出你自己版本的程式，來從數值成績產生字母成績
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
    int grade = 90;
    const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
    string lettergrade;
    if (grade < 60){
        lettergrade = scores[0];
    } else{
        lettergrade = scores[(grade-50)/10];
        if (grade%10>7){
            lettergrade+="+";
        } else if (grade %10 < 3){
            lettergrade+="-";
        }
    }
    cout<< "grade: "<<grade<<endl;
    cout<< "convert to lettergrade "<<endl;
    cout<< "lettergrade: "<< lettergrade<<endl;
    return 0;
}