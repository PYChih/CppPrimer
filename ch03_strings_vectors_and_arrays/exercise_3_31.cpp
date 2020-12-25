// g++ exercise_3_31.cpp && ./a.out
/*
- 練習3.31: 寫一個程式來定義由十個int構成的陣列。賦予每個元素與其在陣列中所在位置相同的值
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
    int index_array[10];
    for (int i=0; i<10; ++i){
        index_array[i] = i;
    }
    for (auto i : index_array){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}