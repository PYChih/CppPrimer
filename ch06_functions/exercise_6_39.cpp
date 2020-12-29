/*
- 練習6.39: 解釋下列每組宣告中第二個宣告的效果。指出何者是非法的，如果有的話。
```
// a: 兩個const都是頂層的，在拷貝的時候會被丟棄，所以這是非法的
int calc(int, int);
int calc(const int, const int); 
// b: 回傳的型別不一樣，也不給重載
int get();
double get();
// c: 可以
int *rest(int *);
double *rest(double *);
```
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() 
{

}