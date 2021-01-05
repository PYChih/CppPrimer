/*
- 練習9.27: 寫一個程式來尋找並移除一個``forward_list<int>``中的奇數值元素。
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
    forward_list<int> ifl = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    auto befor_it = ifl.before_begin();
    auto curr_it = ifl.begin();
    while (curr_it!=ifl.end()){
        if (*curr_it%2){
            curr_it = ifl.erase_after(befor_it);
        } else{
            befor_it = curr_it;
            ++curr_it;
        }
    }
    cout<< "here are ifl erase"<< endl;
    for (auto i : ifl){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}