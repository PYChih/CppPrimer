// Exercise 11.28:
// Define and initialize a variable to hold the result of
// calling find on a map from string to vector of int.
#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

int main(){
    map<string, vector<int>> str_map_ivec{ {"key1", {1, 2, 3}} };
    map<string, vector<int>>::iterator eeit = str_map_ivec.find("key2");
    cout<<(eeit==str_map_ivec.end())<<endl;

}
