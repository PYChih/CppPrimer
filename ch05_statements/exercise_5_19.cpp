/*
- 練習5.19:
寫一個程式，使用do while向使用者重複請求兩個string，並回報哪個string比較短。
g++ exercise_5_19.cpp && ./a.out
 */
#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::string;

int main()
{
    string str1, str2;
    do{
        cin>>str1>>str2;
        auto str1size = str1.size(), str2size = str2.size();
        if (str1size==str2size){
            cout<<"same size"<<endl;
            continue;
        }
        if (str1size<str2size){
            cout<<"str1 short"<<endl;
        } else {
            cout<<"str2 short"<<endl;
        }
    } while(cin);
	return 0;
}