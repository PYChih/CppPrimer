//g++ exercise_3_10.cpp && ./a.out
/*
 * 練習3.10: 寫出一個程式，讀取一串字元，包括標點符號，然後寫出所讀到的東西，但移除標點符號
 */
#include<iostream>
#include <string>
#include<cctype>
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(){
    string line;
    getline(cin, line);
    string new_line = "";
    for (auto s: line){
        if (!ispunct(s))
            new_line+=s;
    }
    cout << "new_line " << new_line << endl;


    return 0;
}