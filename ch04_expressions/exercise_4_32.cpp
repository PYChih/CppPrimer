// g++ exercise_4_32.cpp && ./a.out
/*
- 練習4.32: 解釋下列迴圈。
```
    constexpr int size = 5;
    int ia[size] = {1, 2, 3, 4, 5};
    for (int *ptr = ia, ix=0;
         ix != size && ptr != ia+size;
         ++ix, ++ptr) {}
```
 */
#include<iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main(){
    constexpr int size = 5;
    int ia[size] = {1, 2, 3, 4, 5};
    for (int *ptr = ia, ix=0;
         ix != size && ptr != ia+size;
         ++ix, ++ptr) {}
    return 0;
}