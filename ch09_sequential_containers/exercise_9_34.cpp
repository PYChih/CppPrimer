/*
- 練習9.34: 假設vi是int所組成的，包括偶數值和奇數值的一個容器，請預測下列迴圈的行為。在你分析過這個迴圈後，寫一個程式來測試你的預期是否正確。
// while沒括號，讓++變成最後執行
// 只要有奇數，就會無窮迴圈，insert是往前插入
```
iter = vi.begin();
while (iter != vi.end())
    if (*iter %2)
        iter = vi.insert(iter, *iter);
    ++iter;
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
    vector<int> vi = {0, 1, 2,3, 4, 5, 6, 7, 8, 9};
    auto iter = vi.begin();
    while (iter != vi.end()){
        if (*iter %2)
            iter = vi.insert(iter, *iter);
        ++iter;
    }
    return 0;
}