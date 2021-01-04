/*
- 練習8.9: 使用你為$8.1.2 第一個練習所寫的函式來印出一個istringstream物件的內容
- 練習8.1: 寫出接受並回傳一個istream&的函式。這個函式應該持續讀取資料流，直到碰到檔案結尾為止。此函式應該將它所讀到的東西印出至標準輸出。重設資料流，讓它在回傳前變為有效
g++ exercise_8_09.cpp && ./a.out
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

istream& f(istream& is)
{
    string v;
    while (is >> v, !is.eof()){
        if (is.bad()){
            throw runtime_error("資料流損毀");
        }
        if (is.fail()){
            cerr << "error type, we need string" << endl;
            is.clear();
            //is.ignore(100, '\n');
            continue; // will return to while
        }
        cout << v << endl;
    }
    cout << v << endl;
    is.clear();
    return is;
}

int main()
{
    string s = "aaa bbb ccc";
    istringstream record(s);
    f(record);
    return 0;
}