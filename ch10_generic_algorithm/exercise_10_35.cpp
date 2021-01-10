// Exercise 10.35:
// Now print the elements in reverse order using ordinary iterators.

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
    // print the elements in reverse order using ordinary iterators
    cout<<ivec.size()<<endl;
    for (auto i=ivec.size(); i>0; --i){
        cout<< ivec[i-1]<<" ";
    }
    cout<<endl;
    return 0;
}