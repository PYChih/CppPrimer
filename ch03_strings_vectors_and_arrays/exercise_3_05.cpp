//g++ exercise_3_05.cpp && ./a.out
/*
 * 練習3.5: 寫一個程式從標準輸入讀取string，並將讀取到的串接起來放到一個大型的string中。將串接後的string印出。接著，更改程式，以一個空格分隔相鄰的輸入。
 */
#include<iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(){
    string line_1, line_2;
    if (cin >> line_1){
        while (cin >> line_2){
            if (line_2=="y"){
                break;
            }
            //line_1 += line_2;
            line_1 += " " + line_2;
        }
        cout << line_1 << endl;

    }
    return 0;
}