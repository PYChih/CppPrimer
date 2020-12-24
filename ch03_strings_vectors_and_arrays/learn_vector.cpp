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
    //vector<int> v2;
    //for (int i = 0; i != 100; ++i){
    //    v2.push_back(i);
    //}
// 3.3.3 vector index 
  // use range for
    //vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8, 9};
    //for (auto &i : v1)
    //    i *= i;
    //for (auto i : v1)
    //    cout<< i << " ";
    //cout<<endl;
  //grades split
    vector<int> grades{42, 65, 95, 100, 30, 67, 95, 76, 88, 76, 83, 92, 76, 93};
    vector<int> bins(11, 0);
    for (auto i : grades){
        bins[i/10]+=1;
    }
    for (auto i : bins){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;

}