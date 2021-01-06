/*
- 練習9.38: 寫一個程式來探索在你所用的程式庫中vector如何成長。
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
void print_capacity_and_size(vector<int>& ivec){
    cout<<"current capacity:"<<ivec.capacity()<<" "
        <<"current size: "<<ivec.size()<<endl;
}
int main(){
    vector<int> ivec;
    auto cap = ivec.capacity();
    for (int i=0; i<5000; ++i){
        ivec.push_back(i);
        if (cap!=ivec.capacity()){
            cap = ivec.capacity();
            print_capacity_and_size(ivec);
        }

    }
    return 0;
}