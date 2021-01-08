// Exercise 10.7:
// Determine if there are any errors in the following programs and, if so, correct the error(s)
//    // (a)
//    vector<int> vec;
//    list<int> lst;
//    int i;
//    while (cin >> i)
//        lst.push_back(i);
//    // (b)
//    vector<int> v;
//    v.reserve(10);
//    fill_n(v.begin(), 10, 0);
#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<algorithm>
using std::vector; using std::cout; using std::endl; using std::list; using std::cin; using std::fill_n;
int main(){
    // (a)
    vector<int> vec;
    list<int> lst;
    int i;
    while (cin >> i)
        lst.push_back(i);
    copy(lst.cbegin(), lst.cend(), back_inserter(vec)); // replace vec.begin() to back_inserter
    for (auto i : lst){
        cout<<i<<" ";
    }
    cout<<endl;
    // (b) !!!size v still zero
    vector<int> v;
    //v.reserve(10);
    v.resize(10);
    fill_n(v.begin(), 10, 0);
    for (auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}