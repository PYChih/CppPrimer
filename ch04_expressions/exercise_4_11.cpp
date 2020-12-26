//g++ exercise_4_11.cpp && ./a.out
/*
- 練習4.11: 寫一個運算式測試四個值a、b、c與d，確保a大於b，而b大於c，c大於d。
 */
#include<iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(){
    //int a=1, b=2, c=3, d=4;
    int a=4, b=3, c=2, d=1;
    if (a>b && b>c && c>d){
        cout<< "good order"<<endl;
    } else{
    cout<< "bad order"<<endl;
    }
    return 0;
}