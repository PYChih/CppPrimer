//g++ exercise_3_03.cpp && ./a.out
/*
 * 練習3.3: 解釋空白字元在string輸入運算子及getline函式中是如何被處理的
 * - 一般的cin: 忽略前導空白，遇到空白停止
    - getline: 沒有放棄前導空白、讀到換行結束。
 */
#include<iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(){
    string line;
    char test_char;
    char test_char2;
    cin >> test_char >> test_char2;
    cout << "print " << test_char << endl;
    cout << "print " << test_char2 << endl;
    return 0;
}