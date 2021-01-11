// Exercise 11.15:
// Using a map iterator write an expression that assigns a value to an element.
//
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
using std::string;
using std::vector;
using std::map;
using std::cin;
using std::cout;
using std::endl;
using std::pair;

int main(){
    map<int, int> imapi{{1, 2}, {2, 3}, {3, 4}};
    auto beg = imapi.begin();
    for (const auto &i : imapi){
        cout<<i.first << " -key " << i.second << "-value"<<endl;
    }
    beg->second = 99;
    for (const auto &i : imapi){
        cout<<i.first << " -key " << i.second << "-value"<<endl;
    }
    return 0;
}