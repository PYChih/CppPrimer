//g++ exercise_4_12.cpp && ./a.out
/*
- 練習4.12: 假設i、j與k全都是int，請解釋i!=j<k的意義
// <的優先級比!=高喔
 */
#include<iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;
/*
int main(){
    int i=0;
    bool j=true;
    if (i==j){
        cout<<i<<"==true return true"<<endl;
    }else{
        cout<<i<<"==true return false"<<endl;
    }
    return 0;
}
 */
int main(){
    int i=-10;
    bool j = true;
    if (i<j){
        cout<<i<<"<true return true"<<endl;
    } else{
        cout<<i<<"< true return false"<<endl;
    }
}