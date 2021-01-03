/*
- 練習7.48: 假設Sales_data的建構器不是explicit，下列定義中會發生什麼運算呢?如果Sales_data建構器是explicit，會發生什麼事呢?
```
string null_isbn("9-999-99999-9"); //創建了一個叫null_isbn的string
Sales_data item1(null_isbn);//用一個string初始化了Sales_data
Sales_data item2("9-999-99999-9");
// 沒差別
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