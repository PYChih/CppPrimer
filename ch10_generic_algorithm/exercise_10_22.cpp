// Exercise 10.22:
// Rewrite the program to count words of size 6 or less using
//          functions in place of the lambdas.

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;
using std::placeholders::_1;

bool less_equal_sz(const string &s, string::size_type sz)
{
    return s.size()<=sz;
}
int main(){
    string s{"aaaaaa"};
    unsigned sz=6;
    auto g = bind(less_equal_sz, _1, sz);
    cout<<g(s)<<endl;
    return 0;
}