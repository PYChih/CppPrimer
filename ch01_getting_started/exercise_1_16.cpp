/*
 * 練習1.16: 寫出你自己的程式，從cin讀取一組整數並印出他們的總和
 * control-d 
 *  */

#include <iostream>
int main()
{
    std::cout<< "Enter a sequence of number and press ctrl+d to compute sum" << std::endl;
    int sum=0, value = 0;
    while (std::cin >> value)
        sum += value;
    std::cout << "Sum is : " << sum <<std::endl;
    return 0;
}