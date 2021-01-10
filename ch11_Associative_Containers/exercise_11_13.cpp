//  Exercise 11.9:
//  There are at least three ways to create the pairs in the program for the previous exercise.
//  Write three versions of that program, creating the pairs in each way.
//  Explain which form you think is easiest to write and understand, and why.
#include <vector>
#include <utility>
#include <string>
#include <iostream>
using namespace std;

// 1 default value initializes
/*
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
 */ 
// 2 Serial initialization
pair<string, int> process(string & s, const int i){
    return {s, i};
}
int main(){
    pair<string, int> str_int_pair;
    vector<pair<string, int>> vec_pair;
    string s;
    int i;
    while(cin>>s>>i){
        //vec_pair.push_back(process(s, i));
        //3 make pair
        vec_pair.push_back(make_pair(s, i));
    }
    int cnt=0;
    for (const auto i:vec_pair){
        cout<<cnt<<endl;
        cout<<i.first<<" "<<i.second<<" ; "<<endl;
        ++cnt;
    }
    return 0;
}