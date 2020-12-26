//g++ exercise_4_05.cpp && ./a.out
/*
- 練習4.5: 判斷下列運算式的結果
a. -30 * 3 + 21 / 5 // -86
b. -30 + 3 * 21 / 5 // -18
c. 30 / 3 * 21 % 5 // 0
d. -30 / 3 * 21 % 4 // -210%4 : -2
 */
#include<iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(){
    cout << "a: " << -30*3 + 21/5<<endl;
    cout << "b: " << -30+3*21/5<<endl;
    cout << "c: " << 30/3 * 21 % 5 <<endl;
    cout << "d: " << -30 / 3 * 21 % 4 << endl;
    return 0;
}