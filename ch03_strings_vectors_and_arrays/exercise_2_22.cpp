/*
- 練習3.22: 修改會印出text第一個段落的迴圈，改為將text中對應到第一個段落的元素全都變為大寫。更改text後印出其內容
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
    vector<string> text;
    vector<char> alphabet;
    for (auto it = text.cbegin();
        it != text.cend() && !it->empty(); ++it)
        char tempchar;
        auto ju = it;
        for (auto alpha = ju->begin(); alpha!=ju->end(); ++alpha){
            cout << toupper(*alpha)<<endl;
        }

        
    return 0;
}