/*
- 練習9.10: 下列四個物件的型別為何?
    ```
    vector<int> v1; //vector<int>
    const vector<int> v2; //const vector<int>
    auto it1 = v1.begin();//vector<int>::iterator
    auto it2 = v2.begin();//vector<int>::const_iterator
    auto it3 = v1.cbegin();//vector<int>:: const_iterator
    auto it4 = v2.cbegin();//vector<int>::const_iterator
    ```
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
    return 0;
}