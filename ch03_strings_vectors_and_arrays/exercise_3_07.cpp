//g++ exercise_3_07.cpp && ./a.out
/*
 * 練習3.6: 使用一個範圍for來將一個string中的所有字元改為X。
 * 練習3.7: 如果你將前面練習的迴圈控制變數定義為型別char，會發生什麼事？預測結果，然後修改你的程式，使用一個char看看你是否正確
 */
#include<iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(){
    string st{"abcdefg"};
    for (char &s: st){
        s = 'x';
    }
    cout << "st: " << st<< endl;

    return 0;
}