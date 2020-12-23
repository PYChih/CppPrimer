//g++ exercise_3_06.cpp && ./a.out
/*
 * 練習3.6: 使用一個範圍for來將一個string中的所有字元改為X。
 */
#include<iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(){
    string st{"abcdefg"};
    for (auto &s: st){
        s = 'x';
    }
    cout << "st: " << st<< endl;

    return 0;
}