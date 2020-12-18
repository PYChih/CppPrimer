/*
 * ### 1.4.4 if述句(P17)
 * 計數輸入中每個不同的值連續出現幾次
 */
#include <iostream>
int main()
{
    int currVal = 0, val = 0;
    if (std::cin >> currVal){
        int cnt =1;
        while (std::cin >> val){
            if (val==currVal)
                ++cnt;
            else {
                std::cout << currVal << " occurs "
                          << cnt << " times" << std::endl;
                currVal = val;
                cnt = 1;
            }
        }
        std::cout << currVal<< " occurs "
                  << cnt << " times" << std::endl;
    }
    return 0;
}