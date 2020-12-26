//g++ exercise_4_23.cpp && ./a.out
/*
- 練習4.23: 下列運算式出於運算子優先序的關係無法編譯。使用表4.12，解釋為何出錯。你會如何進行修正?
```
string s = "word";
string p1 = s + s[s.size() - 1]== 's' ? "" : "s";
```
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
    string s = "word";
    string p1 = s + (s[s.size() - 1]== 's' ? "" : "s");
    cout<<p1<<endl;
    return 0;
}