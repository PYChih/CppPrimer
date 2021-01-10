// Exercise 10.34:
// Use reverse_iterators to print a vector in reverse order.

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>
#include<functional>
using namespace std;

int main(){
    vector<int> ivec{1, 2, 3, 4, 5};
    ostream_iterator<int> os_it(cout, " ");
    copy(ivec.begin(), ivec.end(), os_it);
    cout<<endl;
    copy(ivec.rbegin(), ivec.rend(), os_it);
    cout<<endl;
    return 0;
}