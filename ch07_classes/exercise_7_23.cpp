/*
- 練習7.23: 寫出你自己版本的Screen類別
    - 一個Screen代表顯示器上的一個視窗
    - 每個Screen都有一個string成員，存放那個Screen的內容
    - 以及三個String::size_type成員，用來代表游標的位置和畫面的高、寬
    - Screen的使用者不應該知道Screen使用一個string來存放資料
 */

#include <iostream>
#include <string>
using namespace std;

class Screen{
    public:
        typedef string::size_type pos;
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