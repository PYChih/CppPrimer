/*
- 練習9.48:給定前面9.5.3的name和numbers定義。請問numbers.find(name)會回傳什麼呢?
```
string name("AnnaBelle");
string numbers("0123456789")
numbers.find(name); /return string::npos
```
 */
#include<iostream>
#include<deque>
#include<list>
#include<vector>
#include<string>
#include<forward_list>
using std::forward_list;
using std::vector;
using std::string;
using std::list;
using std::deque;
using std::cout;
using std::cin;
using std::endl;
#include<iterator>
using std::begin;
using std::end;
int main(){
    string name("AnnaBelle");
    string numbers("0123456789");
    auto aaa=numbers.find(name);
    cout<<aaa<<endl;
    int bbb=numbers.find(name);
    cout<<bbb<<endl;
    return 0;
}