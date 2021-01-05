/*
- 練習9.19: 改寫前面練習的程式，改用一個list。列出你需要變更的地方
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
    //deque<string> dq;
    list<string> dq;
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