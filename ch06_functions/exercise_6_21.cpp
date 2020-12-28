/*
- 練習6.21: 撰寫一個函式，接受一個int和對int的一個指標，並回傳所接受的int值和指標所指的值之中比較大的那一個。你應該為這個指標使用什麼型別呢?
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int icompareip(const int i, const int* j)
{
    int large_num = 0;
    if (i>*j){
        large_num = i;
    } else if (i<*j){
        large_num = *j;
    } else if (i==*j){
        large_num = *j;
    }
    return large_num;
}

int main(){
    int i=0, j=10, k;
    k = icompareip(i, &j);
    cout<<"k : "<< k<<endl;

    return 0;
}