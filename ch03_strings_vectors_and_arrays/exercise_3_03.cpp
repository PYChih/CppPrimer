//g++ exercise_3_03.cpp && ./a.out
/*
 * 練習3.3: 解釋空白字元在string輸入運算子及getline函式中是如何被處理的
 * - string輸入運算子讀取並捨棄所有的前導空白，然後它持續讀取字元，直到遇到下一個空白字元為止
   - getline: 讀取給定資料流，直到第一個newline，並包括這個newline，並將它所讀到的，但並不包括那個newline，儲存到它的string引數。
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