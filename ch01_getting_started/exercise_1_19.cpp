/*
 * 練習1.19: 修改你為$ 1.4.1的練習所寫的那個會印出一個範圍的數字的程式，讓它能夠處理第一個數字小於第二個的輸入
 * exercise 1.11
 * 練習1.11: 寫個程式提示使用者輸入兩個整數。印出由這兩個整數所指定的範圍內每一個數字
 */
#include <iostream>
int main()
{
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    if (v1>v2){
        int tmp = v2;
        v2 = v1;
        v1 = tmp;
    }
    while (v1<=v2){
        std::cout << v1 << std::endl;
        ++v1;
    }
    return 0;
}