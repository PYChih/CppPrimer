/*
- 練習9.20: 寫一個程式從一個``list</int>``拷貝元素到兩個``deque``中。偶數值元素放到其中一個deque，而奇數的放到另一個。
 */
#include<deque>
using std::deque;
#include<list>
using std::list;
#include<vector>
using std::vector;
#include<string>
using std::string;
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int main(){
    list<int> ilist{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    deque<int> odddeq, evedeq;
    for (auto beg=ilist.cbegin(); beg!=ilist.cend(); ++beg){
        if (*beg%2==0){
            evedeq.push_back(*beg);
        } else{
            odddeq.push_back(*beg);
        }
    }
    for (auto beg=odddeq.begin(); beg!=odddeq.end(); ++beg){
        cout<<*beg<<endl;
    }
    return 0;
}