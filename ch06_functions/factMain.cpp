/*
g++ -c factMain.cpp
g++ -c fact.cpp
g++ factMain.o fact.o -o main
 */
#include<iostream>
#include "Chapter6.h"
#include <string>
using namespace std;

int main(){
    int j;
    cout << "enter an int number "<<endl;
    while (cin >> j){
        if (j<0)
            return -1;
        if (j==0 || j==1){
            cout << j << "! = "<<1<<endl;
        } else{
            cout << j << "! = "<<fact(j)<<endl;
        }
    }

    return 0;
}