/* g++ exercise_3_22.cpp && ./a.out
- 練習3.22: 假設我們有一個名為text的vector<string>，存放了來自一個文字檔案的資料
這個vector中的每個元素要不是一個句子，就是一個空的string，表示段落。
如果我們想要從text印出第一段的內容，我們就得寫一個迴圈，迭代text直到我們遇到空的元素為止: 
修改會印出text第一個段落的迴圈，改為將text中對應到第一個段落的元素全都變為大寫。更改text後印出其內容
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
    vector<string> text = {"aaa", "bbb", ""};
    vector<char> alphabet;
    for (auto it = text.begin();
         it != text.end() && !it->empty(); ++it){
        cout << *it << endl;
        for (auto it2=it->begin();
               it2 != it->end() && !it->empty(); ++it2)
            *it2 = toupper(*it2);
        cout << *it << endl;
        }

        
    return 0;
}