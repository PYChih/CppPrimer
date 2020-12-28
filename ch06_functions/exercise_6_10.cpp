/*
- 練習6.10: 使用指標撰寫一個函式來將兩個int的值對調(swap)。呼叫此函式並印出對調後的值來測試之。
 */
#include<iostream>
#include <string>

using namespace std;

void swap(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp; 
}

int main(){
    int ival=1, jval=2;
    swap(&ival, &jval);
    cout<<"ival : "<<ival << " jval :" << jval<<endl;


    return 0;
}