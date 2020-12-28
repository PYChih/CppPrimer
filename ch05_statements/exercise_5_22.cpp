/*
- 練習5.22: 本節最後一個會跳回``begin``的那個範例用一個迴圈來寫會比較好，請改寫那段程式法，消除``goto``的使用。
 */
#include<iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int get_size(){
    return 1;
}

int main(){
//begin:
//    int sz = get_size();
//    if (sz <=0) {
//        goto begin;
//    }
//
    int sz;
    do{
        sz = get_size();
    } while(sz<=0);
    return 0;
}