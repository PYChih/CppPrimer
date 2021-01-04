/*
- 練習8.13: 改寫這一節的電話號碼程式，從一個具名檔案讀取資料，而非從cin
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct PersonInfo{
    string name;
    vector<string> phones;
};
const string& pseudo_format(const string& s){return s;}
int valid(const string& s){return 1;}
int main()
{
    ifstream file("data/person_numbers");
    string line, word; 
    vector<PersonInfo> people;

    while (getline(file, line)){
    PersonInfo info;
    istringstream record(line);
    record >> info.name;
    while (record>>word)
        info.phones.push_back(word);
    people.push_back(info);
    }

    for (const auto &entry : people){
        ostringstream formatted, badNums;
        for (const auto &nums : entry.phones){
            if (!valid(nums)){
                badNums << " " << nums;
            } else
                formatted << " " << pseudo_format(nums);
        }
        if (badNums.str().empty())
            cout << entry.name << " "
               << formatted.str() << endl;

        else
            cerr << "input error: " << entry.name
                 << " invalid number(s) " << badNums.str() << endl;
    }
    return 0;
}