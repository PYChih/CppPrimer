/*
- 練習6.54: 為一個函式撰寫宣告，它有兩個int參數，並回傳一個int，然後再宣告一個vector，其元素具有這種函式指標型別
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int f1(int, int){
    cout<<"ooo"<<endl;
    return 0;
};

int main() 
{
    using f1FuncType=decltype(f1);
    vector<f1FuncType*> f1vec;

}