/*
- 練習9.42: 寫設你想要一次讀取一個字元到一個string中，而你知道你至少得讀取100個字元，那你會如何增進你程式的效能呢?
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
    string s;
    s.reserve(200);

    return 0;
}