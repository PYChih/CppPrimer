/*
- 練習6.38: 修改arrPtr函式，改回傳對陣列的一個參考。
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int odd[] = {1, 3, 4, 7, 9};
int even[] = {0, 2, 4, 6, 8};
//decltype(odd) *arrPtr(int i)
//{
//    return (i%2) ? &odd : &even;
//}
//
decltype(odd) &arrPtr(int i)
{
    return (i%2) ? odd : even;
}
int main() 
{

}