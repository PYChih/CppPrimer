/*
- 練習9.2: 定義一個list，讓其中的元素是存放int的deque。
 */
#include<iostream>
#include<deque>
#include<list>
using std::list;
using std::deque;
using std::cout;
using std::cin;
using std::endl;

int main(){
    list<deque<int>> ldi{{1,2, 3}, {4, 5, 6}, {7, 8, 9}};
    for (auto i : ldi){
        for (auto j:i){
            cout<<j<<endl;
        }
    }
    return 0;
}