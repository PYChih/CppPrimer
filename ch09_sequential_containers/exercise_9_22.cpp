/*
- 練習9.22: 假設iv是由int組成的一個vector，那麼下列程式哪裡有誤呢?你會如何更正這些問題?
    ```
    vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size()/2;
    while (iter != mid)
        if (*iter == some_val)
            iv.insert(iter, 2*some_val);
    ```
    // 對iv插入元素，那iv的iter會失效喔
    // 兩個改法: 1. 利用insert回傳的iter，然後重設mid 2. 由於迭代次數已知，重寫迴圈
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
    vector<int> iv{1, 2, 3};
    int some_val=1;
    vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size()/2;
    while (iter != mid)
        if (*iter == some_val)
            iv.insert(iter, 2*some_val);
    return 0;
}