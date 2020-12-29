/*
- 練習6.30: 編譯前面所呈現的str_subrange版本，看看你的編譯器會如何處理我們提過的那些錯誤。
g++ exercise_6_30.cpp && ./a.out
error: return-statement with no value, in function returning ‘bool’
arning: control reaches end of non-void function 

```
bool str_subrange(const string &str1, const string &str2)
{
    // 同樣的大小: 回傳正常的相等性測試
    if (str1.size() == str2.size())
        return str1 == str2; // ok: ==return bool
    auto size = (str1.size() < str2.size())
                ? str1.size() : str2.size();
    for (decltype(size) i = 0; i != size; ++i){
        if (str1[i] != str2[i])
            return ; // 錯誤: 沒有回傳值
    }
    //錯誤2: 控制流程可能會流出函式而沒有return
}
```
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool str_subrange(const string &str1, const string &str2)
{
    // 同樣的大小: 回傳正常的相等性測試
    if (str1.size() == str2.size())
        return str1 == str2; // ok: ==return bool
    auto size = (str1.size() < str2.size())
                ? str1.size() : str2.size();
    for (decltype(size) i = 0; i != size; ++i){
        if (str1[i] != str2[i])
            return 0; // 錯誤: 沒有回傳值
    }
    //錯誤2: 控制流程可能會流出函式而沒有return
}

int main(int argc, char **argv)
{
    return 0;
}