//  Exercise 11.33
//  Implement your own version of the word-transformation program.
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<map>
using namespace std;

map<string, string> buildMap(ifstream &map_file)
{
    map<string, string> trans_map;
    string key;
    string value;
    while (map_file >> key && getline(map_file, value))
        if (value.size() > 1)
            trans_map[key] = value.substr(1);
        else 
            throw runtime_error("no rule for " + key);
    return trans_map;
}

const string &
transform(const string &s, const map<string, string> &m)
{
    auto map_it = m.find(s);
    if (map_it != m.cend())
        return map_it->second;
    else
        return s;
    
}

void word_transform(ifstream &map_file, ifstream &input)
{
    auto trans_map = buildMap(map_file);
    string text;
    while (getline(input, text)){
        istringstream stream(text);
        string word;
        bool firstword = true;
        while (stream >> word) {
            if (firstword)
                firstword = false;
            else 
                cout << " ";
            cout << transform(word, trans_map);
        }
        cout << endl;
    }
}

int main(){
    ifstream dic("data/map_dict"), content("data/content");
    //auto map_dict = buildMap(dic);
    // test buildMap
    //for (auto i : map_dict){
    //    cout<<i.first << " : "<<i.second<<endl;
    //}
    //
    // test transform
    //cout<<transform("r", map_dict)<<endl;
    //
    // test transform
    word_transform(dic, content);
    return 0;
}