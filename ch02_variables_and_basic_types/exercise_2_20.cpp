/*
 * 練習2.20: 下列程式會做什麼事呢?
    int i = 42;
    int *p1 = &i;
    *p1 = *p1 * *p1;
/*
 * g++ exercise_2_20.cpp && ./a.out
 */
#include <iostream>
int main()
{
    int i = 42;
    int *p1 = &i;
    std::cout<< " this is p1 initial value" << *p1 << std::endl;
    *p1 = *p1 * *p1;
    std::cout<< "this is p1 now value : " << *p1 << std::endl;
    std::cout<< " 42 times 42 equals to " << 42*42 << std::endl;
	return 0;
}