/*
- ==練習7.46==: 如果有的話，下列哪個述句不是真的?為什麼?
```
a. 一個類別至少必須提供一個建構器。//錯誤: 可以不提供，有合成的預設建構器
b. 預設建構器是具有空的參數列的一個建構器。//正確，但提供預設參數的也是預設建構器
c. 如果一個類別沒有有意義的預設值，類別就不應該提供預設建構器//錯誤，這樣有些情況類別將無法使用
d. 如果一個類別沒有定義預設建構器，編譯器就會產生一個，將每個資料成員初始化為其關聯型別的預設值。//只有在沒有其他建構器的時候，才會生成合成的預設建構器
//對於第二句: 假設定義某個類別成員的時候給了預設值，使用合成的預設建構器的時候會發生啥事?先用預設值還是先預設初始化?
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