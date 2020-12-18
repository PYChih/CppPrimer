/*
 * 練習1.22: 寫一個程式讀取具有相同ISBN的數筆交易紀錄。寫出所讀取的所有交易紀錄之總和。
 */
/*
 * g++ exercise_1_22.cpp && ./a.out < data/book_sales
 */
#include <iostream>
#include "Sales_item.h"
int main()
{
	Sales_item total;
	if (std::cin >> total) {
		Sales_item trans;
		while (std::cin >> trans) {
			if (trans.isbn() == total.isbn())
				total += trans;
			else {
				std::cout << total << std::endl;
				total = trans;
			}
		}
		std::cout << total << std::endl;
	}
	return 0;
}