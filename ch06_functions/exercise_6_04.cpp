/*
- 練習6.4:
編寫一個與使用者互動的函式，請求輸入一個數字並產生該數字的階乘。從main呼叫此函式。
g++ exercise_6_04.cpp && ./a.out
 */
#include<iostream>
#include <string>
using namespace std;

int fact(int val)
{
    int ret = 1;
    while (val>1)
        ret *= val--;
    return ret;

}

int main(){
    int j;
    cout << "enter an int number "<<endl;
    while (cin >> j){
        if (j<0)
            return -1;
        if (j==0 || j==1){
            cout << j << "! = "<<1<<endl;
        } else{
            cout << j << "! = "<<fact(j)<<endl;
        }
    }

    return 0;
}