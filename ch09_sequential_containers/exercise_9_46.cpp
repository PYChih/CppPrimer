/*
- 練習9.46: 使用一個位置和長度改寫前面的練習，以管理string。這次僅使用insert函式。
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
void prefixandsuffix(string & s, string& prefix, string& suffix)
{
    s.insert(0, prefix);
    s.insert(s.size(), suffix);
}
int main(){
    string s("Joe Gibson");
    cout<<"string og "<<s<<endl;
    string prefix("Mr. "), suffix(" Jr.");
    prefixandsuffix(s, prefix, suffix);
    
    cout<<"new string : "<<s<<endl;

    return 0;
}