/*
 * 練習1.9: 寫一個程式用while將50到100的數字加總。
 */
/*
 * g++ exercise_1_09.cpp
 * Sum of 50 to 100 inclusive is 3825
 */ 
#include <iostream>
int main()
{
    int sum = 0, val = 50;
    while (val<101){
        sum += val;
        ++val;
    }
    std::cout << "Sum of 50 to 100 inclusive is "
              << sum << std::endl;
    return 0;
}