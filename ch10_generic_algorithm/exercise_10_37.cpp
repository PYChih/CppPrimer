// Exercise 10.37:
// Given a vector that has ten elements, copy the elements from positions
// 3 through 7 in reverse order to a list.

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<list>
#include<iterator>
#include<algorithm>
#include<functional>
using namespace std;

int main(){
    vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> ilist(5);
    copy(ivec.begin()+3, ivec.begin()+8, ilist.begin());
    for (auto i : ilist){
        cout<<i;
    }
    cout<<endl;
    list<int> rilist(5);
    copy(ivec.rbegin()+2, ivec.rbegin()+8, rilist.begin());
    for (auto i : rilist){
        cout<<i;
    }
    cout<<endl;
    return 0;
}