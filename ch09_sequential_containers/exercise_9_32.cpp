/*
- 練習9.32: 前面程式如果把對insert的呼叫寫成下列這樣，是合法的嗎?如果不是，為什麼呢?``iter = vi.insert(iter, *iter++);``
Segmentation fault (core dumped)
``iter = vi.insert(iter, *iter++);//先做*iter++還是先固定iter-.-``
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
    vector<int> vi = {0, 1, 2,3, 4, 5, 6, 7, 8, 9};
    auto iter = vi.begin();
    while (iter != vi.end()){
        if (*iter % 2) {//if odd
            iter = vi.insert(iter, *iter);
            iter += 2;
            //iter++; iter++; // fix list
        } else // if even
            iter = vi.erase(iter);
    }
    for (auto i : vi){
        cout<<i<<endl;
    }
    return 0;
}