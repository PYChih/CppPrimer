/*
- 練習8.1: 寫出接受並回傳一個istream&的函式。這個函式應該持續讀取資料流，直到碰到檔案結尾為止。此函式應該將它所讀到的東西印出至標準輸出。重設資料流，讓它在回傳前變為有效
 */
#include <iostream>
using namespace std;

istream& f(istream& is)
{
    int v;
    while (is >> v, !is.eof()){
        if (is.bad()){
            throw runtime_error("資料流損毀");
        }
        if (is.fail()){
            cerr << "error type, we need int" << endl;
            is.clear();
            //is.ignore(100, '\n');
            continue; // will return to while
        }
        cout << v << endl;
    }
    is.clear();
    return is;
}

int main()
{
    cout << " input an int, press ctrl+d to end" << endl;
    f(cin);
    return 0;
}