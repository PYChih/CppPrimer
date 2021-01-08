// Exercise 10.6:
// Using fill_n, write a program to set a sequence of int values to 0.
#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<algorithm>
int main(){
    std::vector<int> ivec;
    std::fill_n(back_inserter(ivec), 10, 0);
    for (auto i : ivec){
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
    return 0;
}