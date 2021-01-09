// Exercise 10.24:
// Use bind and check_size to find the first element in a vector of ints that has a value greater
// than the length of a specified string value.

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;
using std::placeholders::_1;

bool check_size(const string &s, string::size_type sz)
{
    return s.size() < sz;
}

int main(){
    string s{"aaaaaa"};
    vector<int> ivec{3, 4, 5, 6, 7, 8, 9};
    cout<<s.size()<<endl;
    auto result = find_if(ivec.begin(), ivec.end(), bind(check_size, s, _1));
    if (result!=ivec.end())
        cout << *result << endl;
    else {
        cout<< "No found" << endl;
    }

    return 0;
}