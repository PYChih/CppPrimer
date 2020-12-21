/*
 * 練習2.13: 下列程式中j的值為何?
/*
 * g++ exercise_2_13.cpp && ./a.out
 */
#include <iostream>
#include <string>
int i = 42;
int main()
{
    int i = 100;
    int j = i;
    std::cout << "i = " << i << " j = " << j << std::endl;
	return 0;
}