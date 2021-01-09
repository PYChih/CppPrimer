// Exercise 10.29:
//   Write a program using stream iterators to read a text file into a vector of strings.

#include<iostream>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>
#include<functional>
using namespace std;

int main(){
    istream_iterator<string> in(cin), eof;
    vector<string> str_vec;
    while(in!=eof)
    {
        str_vec.push_back(*in++);
    }
    for(auto i:str_vec){
        cout<<i<<endl;
    }
    return 0;
}