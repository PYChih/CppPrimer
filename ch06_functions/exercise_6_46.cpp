/*
- 練習6.46: 有可能將isShorter定義為一個constexpr嗎? 若是，就那麼做。如果沒辦法，請解釋原因。// constexpr需要引數和回傳值都是字面值，string不是
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