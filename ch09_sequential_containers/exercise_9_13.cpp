/*
- 練習9.13: 你會如何以一個``list<int>``初始化一個``vector<double>``呢?那以一個``vector<int>``初始化呢?撰寫程式碼來檢查你的答案。
 */
#include<iostream>
#include<deque>
#include<list>
#include<vector>
using std::vector;
using std::list;
using std::deque;
using std::cout;
using std::cin;
using std::endl;
int main(){
    list<int> ilist{1, 2, 3, 4, 5};
    auto beg=ilist.begin(), end=ilist.end();
    vector<int> ivec(beg, end);
    vector<double> dvec(beg, end);

    return 0;
}