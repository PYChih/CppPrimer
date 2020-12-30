/*
- 練習6.55: 寫出四個函式，為兩個int值進行加減乘和除。將這些函式的指標儲存到你為前一個練習所寫的vector
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int add_func(int ival1, int ival2){
    return ival1+ival2;
}

int min_func(int ival1, int ival2){
    return ival1-ival2;
}

int mult_func(int ival1, int ival2){
    return ival1 * ival2;
}

int dev_func(int ival1, int ival2){
    return ival1 / ival2;
}

int main() 
{
    using f1FuncType=decltype(add_func);
    vector<f1FuncType*> f1vec={add_func, min_func, mult_func, dev_func};

}