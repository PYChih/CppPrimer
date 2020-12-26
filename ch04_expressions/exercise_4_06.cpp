//g++ exercise_4_06.cpp && ./a.out
/*
- 練習4.6: 寫一個運算式來判斷一個int值是偶數或奇數
 */
#include<iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(){
    int number = 0;
    if (number%2==0){
        cout<<"even"<<endl;
    } else {
        cout<< "odd" << endl;
    }
    return 0;
}