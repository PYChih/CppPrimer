// g++ exercise_3_35.cpp && ./a.out
/*
- 練習3.35: 使用指標寫一個程式來將一個陣列中的元素設為零。
 */
#include<iostream>
#include <string>
#include <vector>
#include <cctype>
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main(){
    int arr[10];
    int *pts=arr;
    for (int i=0; i<10; ++i){
        *(pts+i) = 0;
    }
    for (auto i : arr){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}