/*
- 練習6.44: 將6.2.2的isShorter函式改寫為inline
```
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}
```
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

inline bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

int main() 
{
    string s1="www", s2="wwww";
    cout<<isShorter(s1, s2)<<endl;


}