//g++ exercise_4_18.cpp && ./a.out
/*
- 練習4.19: 如果ptr指向一個int，而vec是一個vector\<int\>，而ival是一個int，請解釋下列各個運算式的行為。如果有的話，哪一個很可能是不正確的呢?為什麼?要如何更正呢?
a. ``ptr != 0 && *ptr++ //先確認ptr不是空指標，接著確認ptr解參考確定不為0| 這個錯了吧``
b. ``ival++ && ival// 確認ival&&ival``
c. ``vec[ival++] <= vec[ival]// 確定vec是increasing``
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
    vector<int> v{1, 2, 3};
    auto pbeg = v.begin();
    // 印出第一個負值之前的元素
    while (pbeg != v.end() && *pbeg >=0)
        cout << *++pbeg <<endl; //err
    return 0;
}