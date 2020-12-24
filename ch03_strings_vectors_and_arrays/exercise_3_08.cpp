//g++ exercise_3_08.cpp && ./a.out
/*
 * 練習3.6: 使用一個範圍for來將一個string中的所有字元改為X。
 * 練習3.7: 如果你將前面練習的迴圈控制變數定義為型別char，會發生什麼事？預測結果，然後修改你的程式，使用一個char看看你是否正確
 * 練習3.8: 改變第一個練習(3.6)中的程式，先使用一個while，接著再使用一個傳統的for迴圈。這三種做法中你比較喜歡哪一個？為什麼
 */
#include<iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(){
    string st{"abcdefg"};
    //for (auto &s: st){
    //    s = 'x';
    //}
    int s=st.size();
    //int cnt = 0;
    //while (cnt<s){
    //    st[cnt]='x';
    //    ++cnt;
    //}
    for (int i=0; i<s; ++i){
        st[i] = 'x';
    }
    cout << "st: " << st<< endl;

    return 0;
}