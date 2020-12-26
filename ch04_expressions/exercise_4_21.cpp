//g++ exercise_4_21.cpp && ./a.out
/*
- 練習4.21: 寫一個程式來使用條件運算子，找出``vector<int>``中有奇數值的元素，並將每個這種值都變成兩倍。
 */
#include<iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main(){
    vector<int> ivec{1, 2, 3, 4, 5, 6, 7};
    for (auto i : ivec){
        cout<< ((i%2==1)? i*2: i )<<endl;
    }

    return 0;
}