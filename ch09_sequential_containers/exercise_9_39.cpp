/*
- 練習9.39:解釋下列的程式片段做些什麼事:
```
vector<string> svec;
svec.reserve(1024);
string word;
while (cin >> word)
    svec.push_back(word);
svec.resize(svec.size()+svec.size()/2);
//先確保svec可以裝1024個元素，然後一直用cin添加元素，之後把svec的元素量變成總共有的元素+元素個數/2，應該是用空字串裝滿
```
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

    return 0;
}