// Exercise 10.36:
// Use find to find the last element in a list of ints with value 0.

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
    list<int> ilist{0, 1, 2, 3, 4, 5, 0 , 1, 2, 3};
    auto iter = find(ilist.begin(), ilist.end(), 0);
    ostream_iterator<int> os_iter(cout, " ");
    copy(iter, ilist.end(), os_iter);
    cout<<endl;
    auto iter2 = find(ilist.rbegin(), ilist.rend(), 0);
    copy(iter2.base(), ilist.end(), os_iter);
    cout<<endl;
    return 0;
}