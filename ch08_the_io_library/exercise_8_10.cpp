/*
- 練習8.10: 寫一個程式來將一個檔案的每一行儲存到一個``vector<string>``之中。現在使用一個istringstream來讀取這個vector的每個元素，一次讀取一個字詞。
g++ exercise_8_10.cpp && ./a.out
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string filename = "data/person_numbers";
    ifstream in(filename);
    string line, world;
    vector<string> strvec;
    while(getline(in, line)){
        strvec.push_back(line);
        cout<<line<<endl;
        istringstream record(line);
        while (record >> world){
            cout << world << endl;
        }
    }
    return 0;
}