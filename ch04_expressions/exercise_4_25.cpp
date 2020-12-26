//g++ exercise_4_25.cpp && ./a.out
/*
- 練習4.25: 在int為32位元，char為8位元的機器上只用Latin-1字元集，其中'q'的位元模式是01110001，請問~'q'<<6的值是什麼?
    - ~的優先集高於<<所以~q會先提升為整數並反轉成為10001110，因為位元操作預設為整數，因此q會被提升為整數
    - q會左移6個位元
    - ==C\+\+規定整數按照其補碼形式存儲???
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

    return 0;
}