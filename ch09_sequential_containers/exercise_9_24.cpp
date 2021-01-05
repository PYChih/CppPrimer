/*
- 練習9.24: 寫一個程式使用at、下標運算子、front和begin擷取一個vector中的第一個元素，以一個空的vector測試你的程式。
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
    //vector<int> c{2};
    vector<int> c;
    cout << "c.size() : "<<c.size()<<endl;
        auto val1 = c[0];
        auto val2 = c.front();
        auto val3 = *c.begin();
        cout << "val1 "<<val1<<endl;
        cout << "val2 "<<val2<<endl;
        cout << "val3 "<<val3<<endl;
        auto val4 = c.at(0);
        cout << "val4 "<<val4<<endl;
    return 0;
}