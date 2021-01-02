/*
- 練習7.25: Screen能夠安全地仰賴預設版本的拷貝和指定嗎?如果是，為什麼呢?若非，為何不能?
 */

#include <iostream>
#include <string>
using namespace std;

class Screen{
    public:
        typedef string::size_type pos;
        Screen()=default;
        Screen(pos ht, pos wd) : width(wd), height(ht), contents(wd*ht, ' ') {}
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