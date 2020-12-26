//g++ exercise_4_04.cpp && ./a.out
/*
- 練習4.4: 為下列的運算式加上括弧，顯示它是如何被估算的。編譯這個運算式(不帶括弧的)並印出結果來驗證你的答案。
`` 12 / 3 * 4 + 5 * 15 + 24 % 4 /2``
 */
#include<iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(){
    cout<< "ans: "<<12 / 3 * 4 + 5 * 15 + 24 % 4 /2<<endl;
    cout<< "pred "<< (12/3)*4 + 5*15 + (24%4/2)<<endl;
    cout << "compute " <<91<<endl;
    return 0;
}