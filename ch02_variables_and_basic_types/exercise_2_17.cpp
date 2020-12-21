/*
 * 練習2.17: 下列程式碼會印出什麼呢?
    int i, &ri = i;
    i = 5; ri =10;
    std::cout << i << " " << ri << std::endl;
/*
 * g++ exercise_2_17.cpp && ./a.out
 */
#include <iostream>
#include <string>
int main()
{
    int i, &ri = i;
    i = 5;
    ri =10;
    std::cout << i << " " << ri << std::endl;
	return 0;
}