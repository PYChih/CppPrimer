/*
 * 練習2.6: 下列定義之間的差異是什麼(如果有的話)?
 * int month =9, day =7;
 * int month = 09, day = 07;
 */
/*
 * g++ exercise_2_06.cpp && ./a.out
 */
/*
error: invalid digit "9" in octal constant
 */
#include <iostream>
int main()
{
    //int month = 9, day = 7;
    //int month = 09;
    int day = 07;
    //std::cout << month;
    std::cout << day << std::endl; 
    return 0;
}
