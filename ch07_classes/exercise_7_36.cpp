/*
- 練習7.36: 下列的初始器有誤。找出並修正問題。
```
// rem先初始化，base才初始化，因此這邊的rem會以未定義的base%j來初始化，可以把定義順序反過來修正
struct X {
    X (int i, int j): base(i), rem(base % j) {}
    int rem, base;
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