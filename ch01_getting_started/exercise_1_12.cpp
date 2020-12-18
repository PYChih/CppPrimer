/*
 * 練習1.12: 下列for迴圈會做什麼呢? sum的最終值是什麼呢?
    ```
    int sum = 0;
    for (int i = -100; i<=100; ++i)
        sum +=1;
    ```
 */
/*
 * g++ exercise_1_12.cpp
 */ 
#include <iostream>
int main()
{
    int sum = 0;
    for (int i = -100; i<=100; ++i)
        sum +=i;
    std::cout << sum << std::endl;
    return 0;
}