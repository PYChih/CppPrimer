/*
 * 1.4.3 讀取未知數量的輸入(P15)
 * 請使用者輸入一組要加總的數字。在這個情況中，我們並不知道要相加的數字有多少個。
 * control-d 
 */

#include <iostream>
int main()
{
    int sum=0, value = 0;
    while (std::cin >> value)
        sum += value;
    std::cout << "Sum is : " << sum <<std::endl;
    return 0;
}