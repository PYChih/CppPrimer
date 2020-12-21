/*
 * 練習2.14: 下列程式合法嗎？若是，印出的會是什麼值呢？
/*
 * g++ exercise_2_14.cpp && ./a.out
 * 
 */
#include <iostream>
#include <string>
int main()
{
    int i = 100, sum = 0;
    for (int i = 0; i != 10; ++i)
        sum += i;
    std::cout << i << " " << sum << std::endl;
	return 0;
}