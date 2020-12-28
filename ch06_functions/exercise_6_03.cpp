/*
- 練習6.3:
撰寫並測試你自己版本的fact。
g++ exercise_6_03.cpp && ./a.out
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