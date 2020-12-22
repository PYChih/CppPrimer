/*
 * 練習2.26: 下列何者是合法的？
 * a. const int buf; //x : const int buf = 0
 * b. int cnt = 0; //定義一個int
 * c. const int sz = cnt; //定義一個const int
 * d ++cnt; ++sz; // const不能被改變
 */
/*
 * g++ exercise_2_26.cpp && ./a.out
 */
#include <iostream>
int main()
{
    const int buf=10;
    int i = 1;
    std::cout<< i+buf<< std::endl;
	return 0;
}