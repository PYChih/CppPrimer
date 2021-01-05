/*
- 練習9.25: 在前面刪除了一個範圍元素的程式中，如果elem1和elem2相等，會發生什麼事?如果elem2或elem1與elem2兩者都是off-the-end迭代器呢?
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
    
    list<string> slist;
    cout<<(slist.begin()==slist.end())<<endl;
    decltype(slist.begin()) elem1= slist.begin(), elem2 = slist.end(), elem3;
    elem3 = slist.erase(elem1, elem2);

    return 0;
}