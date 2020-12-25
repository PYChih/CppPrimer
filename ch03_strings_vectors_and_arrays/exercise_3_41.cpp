// g++ exercise_3_41.cpp && ./a.out
/*
- 練習3.41: 寫出一個程式從一個int陣列初始化一個vector
 */
#include<iostream>
#include <string>
#include <vector>
#include <iterator>
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main(){
    int int_array[] = {1, 2, 3, 4, 5};
    vector<int> int_vector(int_array, int_array+3);
    for (auto i : int_vector){
        cout<<i<<" ";
    }
    cout<<endl;
    std::begin(int_array);
    return 0;
}