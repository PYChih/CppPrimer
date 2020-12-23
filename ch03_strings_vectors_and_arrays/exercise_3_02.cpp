//g++ exercise_3_02.cpp && ./a.out
/*
 * 練習3.2: 寫一個程式，一次讀取一行的標準輸入。修改你的程式，改成一次讀取一個字詞。
 */
#include<iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(){
    string line;
    //while (getline(cin, line))
    //    cout << line << endl;
    while (cin >> line)
        cout << line << endl;
    return 0;
}