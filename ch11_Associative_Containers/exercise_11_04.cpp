// Exercise 11.4:
// Extend your program to ignore case and punctuation.
// For example, “example.” “example, ” and “Example” should
// all increment the same counter.
//      Exercise 11.3:
//      Write your own version of the word-counting program.
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <cctype>

using std::remove_if;
using std::string;
using std::cin;
using std::cout;
using std::map;
using std::set;
using std::endl;


void str_tolower(string &word){
    for(auto &i : word){
        i = tolower(i);
    }
}


int main()
{
    map<string, size_t> word_count;
    set<string> exclude = {",", ".", " "};
    string word;
    while (cin>>word){
        str_tolower(word);
        // note: remove_if will return pass-then-end iterator for the new end of the range, that's why we need to erase
        word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
        ++word_count[word];
    }
    for (const auto &w : word_count){
        cout<<w.first << " occors " << w.second
            << ((w.second > 1) ? " times" : " time") <<endl;
    }
    return 0;
}