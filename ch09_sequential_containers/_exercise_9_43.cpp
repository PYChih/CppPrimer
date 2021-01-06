/*
- 練習9.43: 寫一個函式，它接受三個string、s、oldVal與newVal。使用迭代器以及insert和erase函式，將s中出現的所有oldVal都取代為newVal。用它來取代常見的縮寫，例如把"tho"取代為"though"或"thru"取代為"through"，藉此測試你的函式
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
    s.erase(s.begin(), s.begin()+oldVal.size());
    s.insert(0, newVal);

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