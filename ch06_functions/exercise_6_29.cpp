/*
- 練習6.29: 當你在一個範圍for中使用一個initializer_list，你會使用一個參考作為迴圈的控制變數嗎? 若是，為什麼呢? 
如果不是，為何不呢?//initializer_list中的元素永遠都是const，所以一般來說沒必要特別設成參考，除非裡面裝的是容器類別，不知道有多大，那避免複製就用參考((不過initializer好像也不會真的複製?) 
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(int argc, char **argv)
{
    return 0;
}