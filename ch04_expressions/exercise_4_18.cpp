//g++ exercise_4_18.cpp && ./a.out
/*
- 練習4.18: 如果前面印出一個vector的元素的while迴圈使用前綴遞增運算子，會發生什麼事?// 由於前綴會回傳加了之後的值，程式會印出超過vector最後一個元素一個位置的值
```
auto pbeg = v.begin();
// 印出第一個負值之前的元素
while (pbeg != v.end() && *beg >=0)
    cout << *pbeg++ <<endl; 印出目前的值，並推進pbeg
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
    vector<int> v{1, 2, 3};
    auto pbeg = v.begin();
    // 印出第一個負值之前的元素
    while (pbeg != v.end() && *pbeg >=0)
        cout << *++pbeg <<endl; //err
    return 0;
}