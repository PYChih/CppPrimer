/*
- 練習6.7: 撰寫一個會在它第一次被呼叫時回傳0，然後之後每次呼叫就依序產生對應數字的函式。
g++ exercise_6_07.cpp && ./a.out
 */
#include<iostream>
#include <string>

using namespace std;

int count_calls()
{
    static int ctr = 0;
    return ctr++;
}

int main(){
    int cnt=0;
    for (int i=0; i<10; ++i){
        cnt=count_calls();
        cout<<"current cnt "<<cnt<<endl;
    }
    return 0;
}