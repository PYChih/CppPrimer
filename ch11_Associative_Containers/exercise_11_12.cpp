//  Exercise 11.12:
//  Write a program to read a sequence of strings and ints,
//  storing each into a pair. Store the pairs in a vector.

#include <vector>
#include <utility>
#include <string>
#include <iostream>
using namespace std;


int main(){
    pair<string, int> str_int_pair;
    vector<pair<string, int>> vec_pair;
    while(cin>>str_int_pair.first>>str_int_pair.second){
        vec_pair.push_back(str_int_pair)
        ;
    }
    int cnt=0;
    for (const auto i:vec_pair){
        cout<<cnt<<endl;
        cout<<i.first<<" "<<i.second<<" ; "<<endl;
        ++cnt;
    }
    return 0;
}
