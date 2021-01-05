/*
- 練習9.5: 改寫前面的程式來回傳一個迭代器指向所要求的元素。注意到這個程式必須處理沒有找到那個元素的情況。
 */
#include<iostream>
#include<deque>
#include<list>
#include<vector>
using std::vector;
using std::list;
using std::deque;
using std::cout;
using std::cin;
using std::endl;

using viter = vector<int>::iterator;
viter find_int_vector(viter beg, viter end, int val)
{
    if (beg==end){
        return end;
    }
    while (beg<end){
        if (*beg==val){
            return beg;
        }
        ++beg;
    }
    return end;
}

int main(){
    vector<int> ivec{1, 2, 3, 4, 5, 6, 7};
    //vector<int> ivec;
    viter ans;
    int fval=3;
    ans = find_int_vector(ivec.begin(), ivec.end(), fval);
    if (ans==ivec.end()){
        cout<<"no find"<<endl;
    } else{
        cout<<"find " << *ans << " in " <<ivec.end() - ans << "-th value"<<endl;
    }
    return 0;
}