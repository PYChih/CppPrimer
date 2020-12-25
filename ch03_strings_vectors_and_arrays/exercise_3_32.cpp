// g++ exercise_3_32.cpp && ./a.out
/*
- 練習3.32: 將你在前面定義的陣列拷貝到另一個陣列。使用vector改寫你的程式。
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
    int copy_index_array[10];
    vector<int> index_vector;
    vector<int> copy_index_vector;
    for (int i=0; i<10; ++i){
        index_array[i] = i;
        index_vector.push_back(i);
    }
    for (auto i : index_array){
        cout<<i<<" ";
        copy_index_array[i] = i;
    }
    copy_index_vector = index_vector;
    cout<<endl;
    return 0;
}