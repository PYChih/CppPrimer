//g++ exercise_4_09.cpp && ./a.out
/*
- 練習4.9: 解釋下列if中條件的行為:
```
const char *cp = "Hello World";
if (cp && *cp)
// cp是一個指向const char的指標
// 首先檢查cp是不是空指標，因為不是，所以繼續檢查*cp
// 檢查*cp是不是指向空字串'\0'不是的話回傳True
```
 */
#include<iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(){
    return 0;
}