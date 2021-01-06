/*
- 練習9.41: 寫一個程式從一個``vector<char>``初始化一個字串。
 */
#include<iostream>
#include<deque>
#include<list>
#include<vector>
#include<string>
#include<forward_list>
using std::forward_list;
using std::vector;
using std::string;
using std::list;
using std::deque;
using std::cout;
using std::cin;
using std::endl;
#include<iterator>
using std::begin;
using std::end;
int main(){
    vector<char> charvec{'h', 'e', 'l', 'l', 'o'};
    string s1(charvec.begin(), charvec.end());
    cout<<s1<<endl;

    return 0;
}