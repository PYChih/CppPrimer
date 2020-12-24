/*
- 練習3.23: 寫一個程式來建立帶有十個int元素的一個vector。使用一個迭代器將每個元素的指定為目前值的兩倍。印出這個vector來測試你的程式。
 */
#include<iostream>
#include <string>
#include <vector>
#include <cctype>
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
int main(){
    vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto it = ivec.begin(); it != ivec.end(); ++it){
        *it = *it * *it;
        cout<< *it << endl;
    }
    return 0;
}