//g++ exercise_3_20.cpp && ./a.out
/*
- 練習3.20: 將一組整數讀到一個vector中。印出每對相鄰元素的和。更改你的程式，改印出第一與最後一個元素的和，後面接著第二個和倒數第二個的和，依此類推。
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
	// Q1
    vector<int> ivec;
    int i;
    char s;
    cout<<"a sequence of int"<<endl;
    while(cin >> i){
        ivec.push_back(i);
        s = getchar();
        if (s=='\n')
            break;
    }
    cout<<"your sequence of int : ";
    for (auto j : ivec){
        cout<<j<<" ";
    }
    cout<<endl;
    auto num_int = ivec.size();
    cout<<"number of items in vector : "<<num_int<<endl;
    for (int k = 0; k<num_int-1; ++k){
        //cout<<ivec[i]+ivec[i+1]<<" ";
        int sum = ivec[k]+ivec[num_int-k-1];
        cout<<sum<<" ";
        cout<<"num_int -k-1 is "<<num_int - k<<endl;
        cout<<"sum of "<<ivec[k] << "and " << ivec[num_int-k-1] <<" are "<<sum<<endl;
        //cout<<ivec[i]+ivec[num_int-i]<<" ";
        cout<<"index ivec "<<ivec[k]<<endl;
    }

    // Q2
    return 0;
}