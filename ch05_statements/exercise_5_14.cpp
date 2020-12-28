/*
- 練習5.14: 寫個程式從標準輸入讀取string，尋找重複的字詞。這個程式應該在輸入中找尋一個字詞後緊接著自身的地方。紀錄重複最多的次數，
以及重複的是哪個字。印出次數最多的重複，或印出一個訊息表示沒有任何字詞重複。舉例來說，如果輸入是how now now now brown cow cow那麼輸出就應該指出now這個字出現了三次。
g++ exercise_5_14.cpp && ./a.out
 */
#include<iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int main(){
    string str, prestr, maxstr;
    unsigned max_repeat, cur_repeat;
    if (cin>>str){
        max_repeat = 0;
        cur_repeat = 1;
        prestr = str;
        while (cin>>str){
            if (prestr==str){
                ++cur_repeat;
                if (cur_repeat>max_repeat){
                    max_repeat = cur_repeat;
                    maxstr = str;
                }
            }else{
                cur_repeat=1;
            }
            prestr = str;
        }
    }
    if (max_repeat==0){
        cout<<"no repeat word"<<endl;
    } else{
        cout<<maxstr<<" repeat "<<max_repeat<<" times"<<endl;
    }

    return 0;
}