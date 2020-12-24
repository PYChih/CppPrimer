//g++ exercise_3_16.cpp && ./a.out
/*
- 練習3.19: 列出定義一個vector的三種方法，並賦予它十個元素，每個都有值42。指出要這麼做是否有偏好的方式以及原因。

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
	vector<int> ivec1 {42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
    vector<int> ivec2(10, 42);
    vector<int> ivec3=ivec1;
    vector<int> ivec4 = {42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
    return 0;
}