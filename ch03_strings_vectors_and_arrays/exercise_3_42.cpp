// g++ exercise_3_42.cpp && ./a.out
/*
- 練習3.42: 寫出一個程式來將由int所構成的一個vector拷貝到一個int陣列。
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
    int int_array[10];
    vector<int> int_vector(10, 11);
    unsigned array_index = 0;
    for(auto i : int_vector){
        int_array[array_index] = i;
        ++array_index;
    }
    return 0;
}