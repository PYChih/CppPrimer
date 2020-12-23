//g++ exercise_3_04.cpp && ./a.out
/*
 * 練習3.4: 寫一個程式來讀取兩個string，並回報這些string是否有相同的長度，若非如此，就回報哪個比較長
 */
#include<iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(){
    string line_1, line_2;
    cin >> line_1 >> line_2;
    cout << "print " << line_1 << endl;
    cout << "print " << line_2 << endl;
    if (line_1.size()==line_2.size()){
        cout << " Same size !"<< endl;
    } else {
        string::size_type s_1=line_1.size(), s_2=line_2.size();
        if (s_1>s_2){
            cout << "line 1 large" << endl;
        } else {
            cout << "line 2 large" << endl;
        }
    }
    return 0;
}