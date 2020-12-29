/*
- 練習6.33: 寫一個遞迴函式印出一個vector的內容
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

void print_vector(vector<int> &ivec, int index)
{
    if (!ivec.empty() && index < ivec.size()){
        cout<<ivec[index]<<endl;
        print_vector(ivec, index+1);
    }
}

int rec_factor(int val)
{

    if (val==0){
        return 1;
    }
    if (val>=1){
        return val * rec_factor(val-1);
    }
    return -1 ;
}

int main()
{
    vector<int> ivec{1, 2, 3, 4, 5};
    print_vector(ivec, 0);
    cout<< rec_factor(0) << endl;
    cout<< rec_factor(1) << endl;
    cout<< rec_factor(2) << endl;
    cout<< rec_factor(3) << endl;

    return 0;
}