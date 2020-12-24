//g++ exercise_3_15.cpp && ./a.out
/*
- 練習3.15: 重複前一個程式，但這次改讀取string
 */
#include<iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
int main(){
    vector<string> strvec;
    string istr;
    char cnt = 'y';
    int i;
    while(cin>>istr){
        strvec.push_back(istr);
        cout<<" cont y/n?"<<endl;
        cin>>cnt;
        if (cnt!='y'&&cnt!='Y'){
            break;
        }
    }
    for (auto j : strvec)
        cout<<j;
    cout<<endl;
    return 0;
}