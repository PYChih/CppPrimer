//g++ exercise_3_16.cpp && ./a.out
/*
- 練習3.18: 下列的程式合法嗎? 若非，你會如何修正之?
```
vector<int> ivec;
ivec[0] = 42;
```
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
	vector<int> ivec;
    //ivec[0] = 42;// can't use index to create new item, please use push_back
    ivec.push_back(42);
    cout<<"i am v1[0]"<<ivec[0]<<endl;
    //or
    vector<int> ivec2{42};
    cout<<"i am v2[0]: "<<ivec2[0]<<endl;
    return 0;
}