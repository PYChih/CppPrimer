// Exercise 10.27:
//  In addition to unique, the library defines function named unique_copy that
//  takes a third iterator denoting a destination into which to copy the unique elements.
//  Write a program that uses unique_copy to copy the unique elements from
//  a vector into an initially empty list.

#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<list>
#include<algorithm>
#include<functional>
using namespace std;

int main(){
    list<int> ilist;
    vector<int> ivec{1, 2, 3, 4, 5};
    unique_copy(ivec.begin(), ivec.end(), back_inserter(ilist));
    for (auto i : ilist){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}