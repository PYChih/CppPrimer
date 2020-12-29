/*
- 練習6.25: 撰寫接受兩個引數的一個main函式。串階所提供的引數，並印出所產生的string。
g++ exercise_6_25.cpp && ./a.out aaa ccc
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(int argc, char **argv)
{
    cout << " argc " << argc << endl;
    string s;
    int i=0;
    while (i<argc){
        s+= argv[i];
        ++i;
    }
    cout << " argv1 " <<s<<endl;

    return 0;
}