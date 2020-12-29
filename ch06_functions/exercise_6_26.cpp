/*
- 練習6.26: 寫一個程式接受在本節中呈現的那些選項。印出傳入main的引數之值
-d -o ofile data0
g++ exercise_6_26.cpp && ./a.out -d -o ofile data0
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
    cout << " argv " <<s<<endl;

    return 0;
}