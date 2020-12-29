/*
- 練習6.42: 賦予make_plural(6.3.2)的第二個參數一個's'的預設引數。印出字詞success和failure的單數與複數版本來測試你的程式。
```
//如果ctr大於1，就回傳word的複數版本
string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr > 1) ? word+ending : word;
}
```
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//如果ctr大於1，就回傳word的複數版本
string make_plural(size_t ctr, const string &word, const string &ending="s")
{
    return (ctr > 1) ? word+ending : word;
}
int main() 
{   
    cout<<make_plural(2, "success", "es")<<endl;
    cout<<make_plural(2, "failure")<<endl;
    cout<<make_plural(1, "success")<<endl;
    cout<<make_plural(1, "failure")<<endl;

}