// g++ exercise_3_40.cpp && ./a.out
/*
- 練習3.40: 寫一個程式來定義從字串字面值初始化的兩個字元陣列。現在定義第三個陣列來存放那兩個陣列串接的結果。使用strcpy和strcat來將那兩個陣列拷貝到第三個中。
 */
#include<iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cstring>
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main(){
    char str1[] = "hello ";
    char str2[] = "hello ";
    cout<<strlen(str1)<<endl;
    unsigned str3_len = strlen(str1) + strlen(str2);
    char str3[str3_len-1];
    strcpy(str3, str1);
    strcat(str3, str2);
    cout<<"this is str3: "<<str3<<endl; 
    return 0;
}