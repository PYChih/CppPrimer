//g++ exercise_5_04.cpp && ./a.out
/*
- 練習5.4 解釋下列每個範例，更正你所發現的任何問題
a. 
```
while (string::iterator iter != s.end()){}
```
b. 
```
while (bool status=find(word)){}
    if (!status){}
```
 */
#include<iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(){
    string s{"Hello"};
    string::iterator iter=s.begin();
    while (iter!=s.end()){
        ++iter;
    }
    bool status;
    //while (status=find(word)){}
    //if (!status){}
    return 0;
}