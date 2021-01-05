/*
- 練習9.16: 重複之前的程式，但將一個``list<int>``中的元素與一個``vector<int>``做比較。
 */
#include<iostream>
#include<deque>
#include<list>
#include<vector>
#include<string>
using std::vector;
using std::string;
using std::list;
using std::deque;
using std::cout;
using std::cin;
using std::endl;

bool compare_vector(vector<int>& ivec1, vector<int>& ivec2){
    if (ivec1==ivec2){
        return 1;
    }
    return 0;
}

vector<int>& ilist2ivec(list<int>& ilist, vector<int>& ivec){
    ivec.assign(ilist.begin(), ilist.end());
    return ivec;
}

int main(){
    list<int> ilist1{1, 2};
    vector<int> ivec1{1, 2, 3}, ivec2;
    ivec2 = ilist2ivec(ilist1, ivec2);
    if (compare_vector(ivec1, ivec2)){
        cout<<"same"<<endl;
    } else{
        cout<<"not same"<<endl;
    }
    return 0;
}