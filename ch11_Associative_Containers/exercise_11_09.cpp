// Exercise 11.9:
// Define a map that associates words with a list of
// line numbers on which the word might occur.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <sstream>
using namespace std;

int main()
{
    map<int, list<string>> line_word;
    string line, word;
    int line_cnt = 1;
    while(getline(cin, line)){
        //cout<<line<<endl;
        istringstream record(line);
        while (record >> word){
            line_word[line_cnt].push_back(word);
            //cout<<word<<endl;
        }
        ++line_cnt;
    }
    // output line_word
    for(const auto line_i:line_word){
        cout<<"line num : "<<line_i.first<<endl;
        for(const auto word:line_i.second){
            cout<<word<<" ";
        }
        cout<<endl;

    }

    return 0;
}