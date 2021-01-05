/*
- 練習9.15: 寫一個程式來判斷兩個``vector<int>``是否相等。
 */
#include<iostream>
#include<deque>
#include<list>
#include<vector>
#include<string>
using std::vector;
using std::string;
using std::list;
using std::deque;
using std::cout;
using std::cin;
using std::endl;

bool compare_vector(vector<int>& ivec1, vector<int>& ivec2){
    if (ivec1==ivec2){
        return 1;
    }
    return 0;
}

int main(){
    vector<int> ivec1{1, 2, 3}, ivec2{1, 3};
    if (compare_vector(ivec1, ivec2)){
        cout<<"same"<<endl;
    } else{
        cout<<"not same"<<endl;
    }
    return 0;
}