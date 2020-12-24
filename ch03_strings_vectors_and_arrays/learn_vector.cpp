//g++ learn_vector.cpp && ./a.out
#include<iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main(){
// 3.3.1 vector define and initial
    //vector<string> articles = {"a", "an", "the"};    
// 3.3.2 new item in vector
    vector<int> v2;
    for (int i = 0; i != 100; ++i){
        v2.push_back(i);
    }
    return 0;

}