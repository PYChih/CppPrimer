/*
 * 練習2.8 : 使用轉義序列，寫出一個程式印出2M後面接著一個newline。修改這個程式，印出2，然後一個tab，然後一個M，後面接著一個newline。
 */
/*
 * g++ exercise_2_08.cpp && ./a.out
 */
#include <iostream>

int main()
{
	std::cout << "2\115\12";
	
	std::cout << "2\t\115\12";

	return 0;
}