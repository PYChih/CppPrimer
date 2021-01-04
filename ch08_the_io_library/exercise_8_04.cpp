/*
- 練習8.4: 撰寫一個函式來開啟一個檔案以進行輸入，並將它的內容讀取到一個由string構成的vector中，讓每一行都儲存為這個vector中的一個個別元素。
g++ exercise_8_04.cpp && ./a.out
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
    while (getline(in,s)){
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
