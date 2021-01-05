/*
- 練習9.11: 為創建和初始化一個vector的六種方法都寫出一個例子。解釋每個vector會含有什麼值。
 */
#include<iostream>
#include<vector>
using std::vector;
using std::cout;
using std::cin;
using std::endl;
int main(){
    vector<int> ivec1; // default initialization
    vector<int> ivec2{1, 2, 3, 4, 5};// list initialization same as ivec2 = {1, 2, 3, 4, 5}
    vector<int> ivec3(5); // value initial?
    vector<int> ivec4(5, 1); // value initial
    vector<int> ivec5 = ivec2; // copy initialization same as ivec5(ivec2)
    auto beg = ivec2.begin(), end=ivec2.end();
    vector<int> ivec6(beg, end);
    return 0;
}