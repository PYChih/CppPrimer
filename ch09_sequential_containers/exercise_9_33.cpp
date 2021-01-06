/*
- 練習9.33: 在本節的最後一個例子中，如果我們沒有把insert的結果傳給begin的話會怎樣?寫個省略此指定的程式來看看你的預期是否正確。
``照理說改動vector的元素會讓迭代器失效-.-``
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