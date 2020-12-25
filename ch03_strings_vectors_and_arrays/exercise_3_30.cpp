// g++ exercise_3_30.cpp && ./a.out
/*
- 練習3.30: 辨識出下列程式碼中的索引錯誤:
``` array index begin from zero
constexpr size_t array_size = 10;
int ia[array_size];
for (size_t ix = 1; ix<=array_size; ++ix)
    ia[ix] = ix;
```
 */
#include<iostream>
#include <string>
#include <vector>
#include <cctype>
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main(){
    constexpr size_t array_size = 10;
    return 0;
}