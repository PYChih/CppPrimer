/*
 * 練習1.25: 使用網站上的Sales_item.h標頭，編譯並執行本節中的書店程式。
 */
/*
 * g++ exercise_1_25.cpp && ./a.out < data/book_sales
 */
#include <iostream>
#include "Sales_item.h"
int main()
{
    Sales_item total;
    if (std::cin >> total){
        Sales_item trans;
        while (std::cin >> trans) {
            if (total.isbn() == trans.isbn())
                total += trans;
            else {
                std::cout << total << std::endl;
                total = trans;
            }
        }
        std::cout << total << std::endl;
    }
    else {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    return 0;
}
