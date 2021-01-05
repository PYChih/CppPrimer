/*
- 練習9.23: 在本節的第一個程式中，如果c.size()是1，那val、val2、val3與val4的值會是什麼?
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
    vector<int> c{2};
    cout << "c.size() : "<<c.size()<<endl;
    if (!c.empty()){
        auto val1 = *c.begin(), val2 = c.front();
        auto last = c.end();
        auto val3 = *(--last);
        auto val4 = c.back();
        cout << "val1 "<<val1<<endl;
        cout << "val2 "<<val2<<endl;
        cout << "val3 "<<val3<<endl;
        cout << "val4 "<<val4<<endl;
    }

    return 0;
}