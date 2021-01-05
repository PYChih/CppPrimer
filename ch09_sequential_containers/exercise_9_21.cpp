/*
- 練習9.21: 解釋前面使用insert的回傳值新增元素到一個list的迴圈如果改成插入到一個vector，那要如何才能運作
``//免改，只是性能變差``
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

int main(){
    //list<string> lst;
    vector<string> lst;
    auto iter = lst.begin();
    string word;
    while (cin >> word)
        iter = lst.insert(iter, word);
    return 0;
}