/*
- 練習7.41: 改寫你自己版本的Sales_data類別，改為使用委派建構器。
新增一個述句到每個建構器的主體，讓它們在被執行的時候印出一個訊息。
盡可能以所有方式寫出宣告來建構一個Sales_data物件。
研究輸出，直到你確信你了解委派建構器之間的執行順序為止。
 */

#include "Sales_data_7_4.h"

int main()
{
    cout<<" Sales_data item1; "<<endl;
    Sales_data item1;
    cout<<" Sales_data item2(\"s\", 1, 1)"<<endl;
    Sales_data item2("s", 1, 1);
    cout<<" Sales_data item3(\"s\")"<<endl;
    Sales_data item3("s");
    cout<<" Sales_data item4(cin)"<<endl;
    Sales_data item4(cin);    
    return 0;
}