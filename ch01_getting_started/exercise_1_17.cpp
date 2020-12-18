/*
 * 練習1.17: 如果輸入的值全都相同，那麼本節中的程式會發生什麼事呢？如果沒有重複的數字呢？
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