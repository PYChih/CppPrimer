/*
- 練習6.23: 為本節所呈現的那些print函式寫出你自己的版本。呼叫那些函式中的每一個來印出定義如下的i與j:
``int i = 0, j[2] = {0, 1};``
 */
#include<iostream>
#include<string>
#include<vector>
#include<iterator>
using namespace std;

// two pointer: begin and end
void print1(int *i, int *j)
{
    while (i!=j){
        cout<<*i<<endl;
        ++i;
    }
}

// two param: begin and size
void print2(int *arr, unsigned t)
{
    for (int i=0; i<t; ++i){
        cout<<arr[i]<<endl;
    }
}

int main(){
    int i = 0, j[2] = {0, 1};
    cout<<"print1 "<<endl;
    print1(begin(j), end(j));
    cout<<"print2 "<<endl;
    print2(begin(j), end(j)-begin(j));
    cout<<"print3 "<<endl;
    print2(&i, 1);

    return 0;
}