/*
 * 練習1.21:寫一個程式，讀取兩個具有相同ISBN的Sales_item物件，並產生它們的總和。
 */
/*
 * g++ exercise_1_21.cpp && ./a.out < data/add_item
 */
#include <iostream>
#include "Sales_item.h"
int main()
{
	Sales_item item1, item2;
	std::cin >> item1 >> item2;
	if (item1.isbn() != item2.isbn()) {
		std::cerr << "Data must refer to same ISBN." << std::endl;
		return -1;
	}
	std::cout << item1 + item2 << std::endl;
	return 0;
}