/*
- 練習9.31: 前面移除偶數數值元素並複製奇數值元素的程式在list或forward_list上是行不通的，為什麼呢?請修改程式讓它在這些型別上也可行。
// error: no match for ‘operator+=’ (operand types are ‘std::_List_iterator<int>’ and ‘int’)
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
    forward_list<int> vi = {0, 1, 2,3, 4, 5, 6, 7, 8, 9};
    auto prev_iter = vi.before_begin();
    auto iter = vi.begin();
    while (iter != vi.end()){
        if (*iter % 2) {//if odd
            //iter = vi.insert(iter, *iter); del for forwar_list
            prev_iter = vi.insert_after(iter, *iter);
            iter++; iter++;
            //iter += 2; del for list
            //iter++; iter++; // fix list
        } else // if even
            //iter = vi.erase(iter);
            iter = vi.erase_after(prev_iter);
    }
    for (auto i : vi){
        cout<<i<<endl;
    }
    return 0;
}