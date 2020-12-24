//g++ exercise_3_21.cpp && ./a.out
/*
- 練習3.21: 使用迭代器重新做一遍3.3.3的第一個練習
練習3.16: 寫出一個程式印出練習3.13中那些vector的大小與內容。檢查你對於那個練習的解答是否正確。若非如此，重新研讀3.3.1值到你了解為何出錯為止
 */
#include<iostream>
#include <string>
#include <vector>
#include <cctype>
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
int main(){
    vector<int> v1;// 0個int...
    vector<int> v2(10); // 10個0
    vector<int> v3(10, 42);// 10個42
    vector<int> v4{10};// 一個10
    vector<int> v5{10, 42};// 兩個，10跟42
    vector<string> v6 {10};// 10個空字串
    vector<string> v7{10, "hi"};// 10個hi
    vector<vector<int>> vvi = {v1, v2, v3, v4, v5};
    vector<vector<string>> vvstr = {v6, v7};
    int vector_cnt = 1;
    for (auto it = vvi.begin(); it!=vvi.end(); ++it){
        unsigned num_item = it->size();
        cout<<"v"<<vector_cnt<<" has "<<it->size()<<" items"<<endl;
        for (auto iit=it->begin(); iit!=it->end(); ++iit){
            cout<<*iit<<" ";
        }
        cout<<endl;
        vector_cnt+=1;
    }
    for (auto it = vvstr.begin(); it!=vvstr.end(); ++it){
        unsigned num_item = it->size();
        cout<<"v"<<vector_cnt<<" has "<<it->size()<<" items"<<endl;
        for (auto iit=it->begin(); iit!=it->end(); ++iit){
            cout<<*iit<<" ";
        }
        cout<<endl;
        vector_cnt+=1;
    }
    return 0;
}