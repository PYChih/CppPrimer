/*
 * 1.4.1 while述句(P11.) 
 * 使用一個while來寫出加總數字1到10(包含兩端)的程式
 *  */
#include <iostream>
int main()
{
    int sum = 0, val = 1;
    while (val <=10) {
        sum += val;
        ++val;
    }
    std::cout << "Sum of 1 to 10 inclusive is "
              << sum << std::endl;
    return 0;
}