/*
 * 練習1.10 : 除了會加1到其運算元的++運算子，另外還有一個會減1的遞減運算子(--)。使用遞減運算子寫一個while，印出從十遞減到零的數字
 */
/*
 * g++ exercise_1_10.cpp
 *current val number : 10
 *current val number : 9
 *current val number : 8
 *current val number : 7
 *current val number : 6
 *current val number : 5
 *current val number : 4
 *current val number : 3
 *current val number : 2
 *current val number : 1
 *current val number : 0
 */ 
#include <iostream>
int main()
{
    int val = 10;
    while (val>=0){
        std::cout << "current val number : " << val << std::endl;
        --val;
    }
    return 0;
}