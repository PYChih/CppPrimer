/*
 * 練習2.4: 下面程式碼會產生什麼輸出呢?
unsigned u = 10, u2 = 42;
std ::cout << u2 -u << std::endl;  32
std::cout << u - u2 << std::endl;  large number
int i = 10, i2 = 42;               
std::cout << i2-i<<std::endl;      32
std::cout << i - i2<<std::endl;    -32
std::cout << i - u<< std::endl;    0
std::cout << u - i<<std::endl;     0
 */
/*
 * g++ exercise_2_04.cpp && ./a.out
 */
#include <iostream>
int main()
{
    unsigned u = 10, u2 = 42;
    std::cout << u2 -u << std::endl;  
    std::cout << u - u2 << std::endl;
    int i = 10, i2 = 42;               
    std::cout << i2-i << std::endl;
    std::cout << i - i2 << std::endl;
    std::cout << i - u << std::endl;
    std::cout << u - i << std::endl;
    return 0;
}