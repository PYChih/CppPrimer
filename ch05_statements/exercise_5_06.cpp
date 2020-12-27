//g++ exercise_5_06.cpp && ./a.out
/*
- 練習5.6: 改寫你的成績程式，使用條件運算子來取代if-else述句
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
    (grade<60)? lettergrade=scores[0] : lettergrade=scores[(grade-50)/10];
    cout<< "grade: "<<grade<<endl;
    cout<< "convert to lettergrade "<<endl;
    cout<< "lettergrade: "<< lettergrade<<endl;
    return 0;
}