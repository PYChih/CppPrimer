/*
 * 練習1.11: 寫個程式提示使用者輸入兩個整數。印出由這兩個整數所指定的範圍內每一個數字
 */
/*
 * g++ exercise_1_11.cpp
 */ 
#include <iostream>
int main()
{
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    while (v1<=v2){
        std::cout << v1 << std::endl;
        ++v1;
    }
    return 0;
}