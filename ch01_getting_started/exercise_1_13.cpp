/*
 * 練習1.13: 使用for迴圈改寫$ 1.4.1的頭兩個練習
 */
/*
 * 練習1.9: 寫一個程式用while將50到100的數字加總。
 */
/*
 * 練習1.10 : 除了會加1到其運算元的++運算子，另外還有一個會減1的遞減運算子(--)。使用遞減運算子寫一個while，印出從十遞減到零的數字
 */
#include <iostream>
int main()
{
    int sum1_9 = 0;
    for (int i=50; i<=100; ++i){
        sum1_9+=i;
    }
    std::cout << "Sum of 50 to 100 inclusive is "
              << sum1_9 << std::endl;
    for (int i=10; i>=0; --i){
        std::cout << "current val number : " << i << std::endl;
    }
    return 0;
}