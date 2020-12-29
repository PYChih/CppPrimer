/*
- 練習6.47: 修改你在$6.3.2的練習中寫的那個以遞迴印出一個vector內容的程式，讓它能夠條件式地印出其執行相關的資訊。舉例來說，你可能會在每次呼叫印出vector的大小。編譯並執行該程式，先開啟除錯來執行，然後關閉除錯再次執行。
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

void print_vector(vector<int> &ivec, int index)
{
    if (!ivec.empty() && index < ivec.size()){
#ifndef NDEBUG
    cout<<"current index "<<index<<endl;
#endif
        cout<<ivec[index]<<endl;
        print_vector(ivec, index+1);
    }
}
int main() 
{
    vector<int> ivec{1, 2, 3, 4, 5};
    print_vector(ivec, 0);
}