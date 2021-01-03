/*
- ==練習7.49==: 對於下列三個combine的宣告，解釋如果我們呼叫i.combine(s)，而i是Sales_data，s是一個string，會發生什麼事?
```
Sales_data &combine(Sales_data); // 如果Sales_data(string)的建構器不是explicit，就會隱含的創建一個暫存的Sales_data，然後執行combine的述句
Sales_data &combine(Sales_data&); // 報錯
Sales_data &combine(const Sales_data&) const; // 報錯
```
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{

    return 0;
}