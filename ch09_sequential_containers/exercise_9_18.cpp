/*
- 練習9.18: 寫一個程式從標準輸入讀取一序列的string到一個deque中。使用迭代器撰寫一個迴圈來打印出這個deque中的元素。
 */

#include<deque>
using std::deque;
#include<list>
using std::list;
#include<vector>
using std::vector;
#include<string>
using std::string;
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int main(){
    deque<string> dq;
    string s;
    while(cin>>s){
        dq.push_back(s);
    }
    auto beg = dq.begin(), end = dq.end();
    while(beg!=end){
        cout<<*beg<<endl;
        ++beg;
    }
    return 0;
}