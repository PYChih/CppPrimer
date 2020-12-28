/*
- 練習6.16:下列函式，雖然是合法的，但其用處比預期低。請找出並解除這個函式所受的限制:
`` bool is_empty(string& s) {return s.empty();}``
因為s是普通的參考，可是函數的行為並不會改動到s，所以應該要改成對const string的參考。
限制在於，沒辦法直接傳入"一個字面值"，因為字面值不給參考，而且const string也沒辦法傳入
 */
#include<iostream>
#include <string>

using namespace std;

int main(){
    return 0;
}