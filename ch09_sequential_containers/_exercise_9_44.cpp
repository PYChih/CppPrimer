/*
- 練習9.44: 使用一個索引和replace改寫前一個函式
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
string& replace_oldVal2newVal(string & s, string& oldVal, string& newVal)
{
    //s.erase(s.begin(), s.begin()+oldVal.size());
    //s.insert(0, newVal);
    s.replace(s.begin(), s.begin()+oldVal.size(), newVal);

    return s;
}
int main(){
    string s("thooo");
    cout<<"string og "<<s<<endl;
    string oldVal("tho"), newVal("though");
    string news=replace_oldVal2newVal(s, oldVal, newVal);
    
    cout<<"new string : "<<news<<endl;

    return 0;
}