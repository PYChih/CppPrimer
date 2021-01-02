/*
- 練習7.35: 解釋下列程式碼，指出其中每個名稱的使用分別用到哪個Type或initVal的定義?說明你會如何修正遇到的任何錯誤? // 把回傳型別加上Exercise::
```
typedef string Type;
Type initVal();
class Exercise {
public:
    typedef double Type;
    Type setVal(Type);
    Type initVal();
private:
    int val;
};
Type Exercise::setVal(Type parm) {
    val = parm + initVal();
    return val;
}
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