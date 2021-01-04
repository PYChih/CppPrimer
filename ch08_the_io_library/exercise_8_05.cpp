/*
- 練習8.5: 改寫前面的程式，將每個字詞都儲存成個別的元素。
g++ exercise_8_05.cpp && ./a.out
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void write_a_file(string in_file_name)
{
    // read txt from in_file_name and write txt to out_file_name
    ifstream in(in_file_name);
    vector<string> str_vec;
    string s;
    int cnt=0;
    while (in >> s){
        str_vec.push_back(s);
        cout<<cnt++<<endl;
        cout<<s<<endl;
    }
}

int main()
{
    string in_filename = "data/some_words";
    write_a_file(in_filename);
    return 0;
}