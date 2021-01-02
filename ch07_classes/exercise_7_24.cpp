/*
- 練習7.24: 賦予你的Screen類別三個建構器: 一個預設建構器、接受高寬值並初始化內容來放置給定數目個空白的建構器，以及接受高寬值和一個用作畫面內容的字元的建構器。
 */

#include <iostream>
#include <string>
using namespace std;

class Screen{
    public:
        typedef string::size_type pos;
        Screen()=default;
        Screen(pos ht, pos wd) : width(wd), height(ht) {}
        Screen(pos ht, pos wd, char c) : width(wd), height(ht), contents(ht*wd, c) {}

    private:
        pos cursor = 0; // 游標
        pos height = 0, width = 0;
        string contents;
};


int main()
{
    Screen s1;
    return 0;
}