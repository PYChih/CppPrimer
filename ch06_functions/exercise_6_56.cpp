/*
- 練習6.56: 呼叫那個vector中的每個元素，並印出它們的結果
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int add_func(int ival1, int ival2){
    return ival1+ival2;
}

int min_func(int ival1, int ival2){
    return ival1-ival2;
}

int mult_func(int ival1, int ival2){
    return ival1 * ival2;
}

int dev_func(int ival1, int ival2){
    return ival1 / ival2;
}

int main() 
{
    using f1FuncType=decltype(add_func);
    vector<f1FuncType*> f1vec={add_func, min_func, mult_func, dev_func};

    for(auto fun : f1vec){
        int ival1=10, ival2=10;
        cout<<fun(ival1, ival2)<<endl;
    }

}