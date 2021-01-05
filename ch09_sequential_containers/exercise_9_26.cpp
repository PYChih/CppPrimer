/*
- 練習9.26: 使用下列的ia定義，將ia拷貝到一個vector以及一個list中。使用單迭代器版的earse從你的list移除奇數值，並從你的vector移除偶數值``int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};``
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
#include<iterator>
using std::begin;
using std::end;
int main(){
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> ivect(begin(ia), end(ia));
    cout<< "here are ivect og"<< endl;
    for (auto i : ivect){
        cout<<i<<" ";
    }
    cout<<endl;
    list<int> ilist(begin(ia), end(ia));
    cout<< "here are ilist og"<< endl;
    for (auto i : ilist){
        cout<<i<<" ";
    }
    cout<<endl;

    auto iter = ivect.begin();
    while(iter<ivect.end()){
        if (*iter%2==0){
            iter = ivect.erase(iter);
        } else{
            ++iter;
        }
    }
    cout<< "here are ivect erase"<< endl;
    for (auto i : ivect){
        cout<<i<<" ";
    }
    cout<<endl;

    auto iter2 = ilist.begin();
    while(iter2!=ilist.end()){
        if (*iter2%2==1){
            iter2 = ilist.erase(iter2);
        } else{
            ++iter2;
        }
    }
    cout<< "here are ilist erase"<< endl;
    for (auto i : ilist){
        cout<<i<<" ";
    }
    cout<<endl;    
    return 0;
}