/*
- 練習9.45: 撰寫一個函式，接受代表名稱的一個string和另外兩個string，
分別代表一個前綴(prefix)，例如"Mr."或"Ms."，
以及一個後綴(suffix)，例如"Jr"或"III"。
使用迭代器和insert及append函式，產生並回傳一個新的string，其中後綴和前綴被加到了所給的名稱。
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
    s.append(suffix);
    s.insert(s.begin(), prefix.begin(), prefix.end());
}
int main(){
    string s("Joe Gibson");
    cout<<"string og "<<s<<endl;
    string prefix("Mr. "), suffix(" Jr.");
    prefixandsuffix(s, prefix, suffix);
    
    cout<<"new string : "<<s<<endl;

    return 0;
}