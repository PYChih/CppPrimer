//g++ exercise_3_12.cpp && ./a.out
/*
練習3.12: 如果有的話，下列哪個vector定義是錯誤的? 對於合法的那些，請解釋那些定義做些什麼。不合法的那些，解釋為何不合法。
a. vector<vector<int>> ivec; // 預設初始化
b. vector<string> svec = ivec; // nope: ivec是int喔
c. vector<string> svec(10, "null");//10個叫null的string?
//所以說，float到底可不可以給int阿?
 */
#include<iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
int main(){
    int iAmInt = 4.1;
    float iAmFloat;
    iAmFloat = iAmInt;
    iAmInt = iAmFloat;
    return 0;
}