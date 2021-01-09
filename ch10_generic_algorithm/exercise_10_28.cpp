// Exercise 10.28:
//  Copy a vector that holds the values from 1 to 9 inclusive, into three other containers.
//  Use an inserter, a back_inserter, and a front_inserter, respectivly to add elements to these containers.
//  Predict how the output sequence varies by the kind of inserter and verify your predictions
//  by running your programs.

#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<deque>
#include<forward_list>
#include<iterator>
#include<algorithm>
#include<functional>
using namespace std;

int main(){
    vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> ilist;
    list<int> ilist2;
    list<int> ilist3;
    deque<int> ideq;
    forward_list<int> iflist;
    // front inserter ilist
    copy(ivec.begin(), ivec.end(), front_inserter(ilist));
    for(auto i:ilist){
        cout<<i<<" ";
    }
    cout<<endl;
    // back inserter ilist
    copy(ivec.begin(), ivec.end(), back_inserter(ilist2));
    for(auto i:ilist2){
        cout<<i<<" ";
    }
    cout<<endl;
    //inserter
    copy(ivec.begin(), ivec.end(), inserter(ilist3, ilist3.begin()));
    for(auto i:ilist2){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}