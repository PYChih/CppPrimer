//  Exercise 11.33
//  Our program does no checking on the validity of either input file. 
//  In particular, it assumes that the rules in the transformation file are all sensible. 
//  What would happen if a line in that file has a key, one space, and then the end of the line? 
//  Predict the behavior and then check it against your version of the program.
// throw runtime error
// std::runtime_error
#include<iostream>
#include<unordered_map>
#include<fstream>
#include<sstream>
#include<string>
#include<map>
#include <ctime>
using namespace std;

map<string, string> buildMap(ifstream &map_file)
{
    map<string, string> trans_map;
    string key;
    string value;
    while (map_file >> key && getline(map_file, value))
        if (value.size() > 1)
            //trans_map[key] = value.substr(1);
            trans_map.insert({ key, value.substr(1) });
        else 
            throw runtime_error("no rule for " + key);
    return trans_map;
}
unordered_map<string, string> build_unorder_Map(ifstream &map_file)
{
    unordered_map<string, string> trans_map;
    string key;
    string value;
    while (map_file >> key && getline(map_file, value))
        if (value.size() > 1)
            trans_map[key] = value.substr(1);
            //trans_map.insert({ key, value.substr(1) });
        else 
            throw runtime_error("no rule for " + key);
    return trans_map;
}

int main(){
    ifstream dic("data/map_dict"), content("data/content");
    clock_t time_stt = clock();
    auto map_dict = buildMap(dic);
    cout << "time of order is "
         << 1000 * (clock() - time_stt) / (double) CLOCKS_PER_SEC << "ms" << endl;
    // test buildMap
    for (auto &i : map_dict){
        cout<<i.first << " : "<<i.second<<endl;
    }
    cout<<"unorder"<<endl;
    dic.close();
    dic.open("data/map_dict");
    time_stt = clock();
    auto unorder_map_dict = build_unorder_Map(dic);
    cout << "time of unorder is "
         << 1000 * (clock() - time_stt)/ (double) CLOCKS_PER_SEC << "ms" << endl;
    cout<<"(double) CLOCKS_PER_SEC"<<(double) CLOCKS_PER_SEC<<endl;
    // test buildMap
    for (auto &i : unorder_map_dict){
        cout<<i.first << " : "<<i.second<<endl;
    }
    dic.close();
    cout<<endl;
    return 0;
}