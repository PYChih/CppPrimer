/*
- 練習6.22: 寫一個函式來對調兩個int指標
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

void swapointer(int *(&i), int*(&j))
{
    int * temp;
    temp = i;
    i = j;
    j = temp;
    
}

int main(){
    int i=10, j=0;
    int *k=&i, *l=&j;
    cout<<"k value " << *k << " l value " << *l<<endl;
    swapointer(k, l);
    cout<<"k value " << *k << " l value " << *l<<endl;
    return 0;
}