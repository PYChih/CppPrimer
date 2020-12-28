/*
- 練習6.6: 解釋參數、區域變數，以及區務static變數之間的差異。各自給出一個函式為例，說明他們何時可能會有用處。
g++ exercise_6_06.cpp && ./a.out
參數: 參數是自動物件，參數是在函式主體的範疇中定義的，因此它們會在函式終結時被摧毀。
區域變數: 定義在函數內的變數叫做區域變數，如果配有初始器就會初始化，否則就是預設初始化(這代表內建型別的未初始化區務變數有未定義的值。)
區域static變數: 在函式裡為變數加上static宣告可以成為區域static變數，值就會一直存在值到程式結束被摧毀。
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