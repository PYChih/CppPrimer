/*
 * 練習1.23: 寫一個程式，讀取數筆交易紀錄，並計數每個ISBN出現幾次。
 */
/*
 * g++ exercise_1_23.cpp && ./a.out < data/book_sales
 */
#include <iostream>
#include "Sales_item.h"
int main()
{
	Sales_item item;
	if (std::cin >> item) {
		int cnt = 1;
		Sales_item tmp_item;
		while (std::cin >> tmp_item) {
			if (tmp_item.isbn() == item.isbn())
				++cnt;
			else {
				std::cout << item.isbn() << " has " << cnt << " transaction(s)"
				          << std::endl;
				item = tmp_item;
				cnt = 1;
			}
		}
		std::cout << item.isbn() << " has " << cnt << " transaction(s)"
		          << std::endl;
	}
	return 0;
}