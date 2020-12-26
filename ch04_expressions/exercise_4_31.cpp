// g++ exercise_4_31.cpp && ./a.out
/*
- 練習4.31: 本節中的程式使用前綴遞增和遞減運算子。請解釋為和使用前綴而非後綴呢? 要做什麼變更才能使用後綴版本呢? 使用後綴運算子改寫程式
same but prefix better
 */
#include<iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main(){
    vector<int> ivec{1, 2, 3, 4, 5};
    vector<int>::size_type cnt = ivec.size();
    for (vector<int>::size_type ix=0;
                     ix != ivec.size();
                     ix++, cnt--){
                         ivec[ix] = cnt;
                     }
    return 0;
}