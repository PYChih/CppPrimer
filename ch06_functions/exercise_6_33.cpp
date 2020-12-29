/*
- 練習6.33: 寫一個遞迴函式印出一個vector的內容
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;


void print_vec(vector<int> &ivec1)
{
    auto beg = ivec1.begin();
    auto end = ivec1.end();
    while(beg!=end){
        cout<<*beg<<endl;
        ++beg;
    }
}

void print_vec_recursion(vector<int> &ivec, unsigned index)
{
    unsigned sz = ivec.size();
    if (!ivec.empty() && index < sz){
        cout<<ivec[index]<<endl;
        print_vec_recursion(ivec, index+1);
    }
}

int main() {
    vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    print_vec(ivec);
    print_vec_recursion(ivec, 0);

}