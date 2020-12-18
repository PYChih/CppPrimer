/*
 * 練習1.20: 
 * http://www.informit.com/title/0321714113 
 * 含有Sales_item.h，位在第一章的程式碼目錄中。將那個檔案複製到你的工作目錄。用它來撰寫一個程式，讀取一組書籍販售紀錄，再將每筆交易紀錄寫到標準輸出。
 * 
 */

/*
 * g++ exercise_1_20.cpp && ./a.out < data/book_sales
 */
#include <iostream>
#include "Sales_item.h"
int main()
{
    Sales_item book;
    while (std::cin >> book)
        std::cout << book << std::endl;
    return 0;
}