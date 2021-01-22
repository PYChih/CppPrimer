// Exercise 12.28
//  Write a program to implement text queries
//  without defining classes to manage the data.
//  Your program should take a file and interact
//  with a user to query for words in that file.
//  Use vector, map, and set containers to hold the data for the file and
//  to generate the results for the queries.
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;
using std::map;
using std::set;
int main() {
    ifstream in("data/google_blog");
    vector<string> content;
    string line;
    int line_cnt = 0;
    map<string, set<int>> word2line_set;
    while (getline(in, line)) {
        content.push_back(line);
        istringstream record(line);
        string word;
        while (record >> word) {
            word2line_set[word].insert(line_cnt);
        }
        ++line_cnt;
        // cout << "line : " << line_cnt << endl;
        // cout << line << endl;
    }
    // interact with user
    while (true) {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q") break;
        auto it = word2line_set.find(s);
        if (it == word2line_set.end()) {
            cout << "no find : " << s << endl;
        } else {
            set<int> line_set = it->second;
            for (auto i : line_set) {
                cout << "line No: " << i << endl;
                cout << content[i] << endl;
            }
        }
    }
    // for (auto key : word2line_set) {
    //     cout << key.first << endl;
    //     cout << "line set :" << endl;
    //     for (auto i : key.second) {
    //         cout << i << endl;
    //     }
    // }
    // cout << content[0] << endl;
    return 0;
}
