/*
- 練習9.4: 寫一個函式接受指涉一個``vector<int>``的一對迭代器，以及一個int值。在該範圍中尋找那個值，並回傳bool指出是否有找到。
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
bool find_int_vector(viter beg, viter end, int val)
{
    if (beg==end){
        return 0;
    }
    while (beg<end){
        if (*beg==val){
            return 1;
        }
        ++beg;
    }
    return 0;
}

int main(){
    //vector<int> ivec{1, 2, 3, 4, 5, 6, 7};
    vector<int> ivec;
    bool ans;
    int fval=3;
    ans = find_int_vector(ivec.begin(), ivec.end(), fval);
    cout<<ans<<endl;
    return 0;
}