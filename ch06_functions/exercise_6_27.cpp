/*
- 練習6.27: 撰寫一個函式，接受一個initializer_list\<int\>並產生該串列中元素的總和
g++ exercise_6_27.cpp && ./a.out
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int sum_initializer_list(initializer_list<int> ilist)
{
    int sum=0;
    for (const auto i : ilist){
        sum+=i;
    }
    return sum;
}

int main(int argc, char **argv)
{
    initializer_list<int> ils{1, 2, 3, 4, 5};
    int sum_ilist;
    sum_ilist = sum_initializer_list(ils);
    cout<< "sum of i list "<<sum_ilist<<endl;
    return 0;
}