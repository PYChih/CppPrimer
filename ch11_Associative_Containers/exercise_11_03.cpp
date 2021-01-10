// Exercise 11.3:
// Write your own version of the word-counting program.
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>

using std::string;
using std::cin;
using std::cout;
using std::map;
using std::endl;

int main()
{
    map<string, size_t> word_count;
    string word;
    while (cin>>word){
        ++word_count[word];
    }
    for (const auto &w : word_count){
        cout<<w.first << " occors " << w.second
            << ((w.second > 1) ? " times" : " time") <<endl;
    }
    return 0;
}