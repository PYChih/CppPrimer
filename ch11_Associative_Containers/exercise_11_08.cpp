// Exercise 11.8:
// Write a program that stores the excluded words in a vector
// instead of in a set. What are the advantages to using a set?
//  see this : https://stackoverflow.com/questions/8686725/what-is-the-difference-between-stdset-and-stdvector

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int main()
{
    map<string, size_t> set_word_count, vec_word_count;
    set<string> exclude_set = {"The", "But", "And", "Or", "An", "A",
                                "the", "but", "and", "or", "an", "a"};
    vector<string> exclude_vec = {"The", "But", "And", "Or", "An", "A",
                                "the", "but", "and", "or", "an", "a"};
    string word;
    while (cin>>word){
        if (exclude_set.find(word) == exclude_set.end())
            ++set_word_count[word];
        if (find(exclude_vec.begin(), exclude_vec.end(), word)==exclude_vec.end()){
            ++vec_word_count[word];
        }
    }
    for (const auto &w : set_word_count){
        cout<<w.first << " occors " << w.second
            << ((w.second > 1) ? " times" : " time") <<endl;
    }
    for (const auto &w : vec_word_count){
        cout<<w.first << " occors " << w.second
            << ((w.second > 1) ? " times" : " time") <<endl;
    }
    return 0;
}