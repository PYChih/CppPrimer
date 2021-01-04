/*
- 練習8.11: 這一節中的程式在外層的while迴圈內定義它的istringstream物件。如果record是定義在那個迴圈外，你得做出什麼變更才行?改寫那個程式，將record的定義移到那個while之外，再看看你是否想出了所有必要的變更。
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
    istringstream record;
    while(getline(in, line)){
        strvec.push_back(line);
        cout<<line<<endl;
        //istringstream record(line);
        //while (record >> world){
        //    cout << world << endl;
        //}
        record.clear();
        record.str(line);
        while (record >> world){
            cout << world << endl;
        }


    }
    return 0;
}