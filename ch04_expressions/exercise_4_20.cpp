//g++ exercise_4_20.cpp && ./a.out
/*
- 練習4.20: 假設iter是一個``vector<string>::iterator``，指出下列哪些運算式是合法的(如果有的話)。以及那些不合法的錯在哪裡。
a. ``*iter++; // 合法，回傳iter解參考後的值並且把iter+1``
b. ``(*iter)++; //不合法，把iterator解參考，之後把值加一，可是值是string不給加1``
c. ``*iter.empty() // 不合法，.的優先級比*高，然後iter沒有定義empty``
d. ``iter->empty() // 合法，等價於(*iter).empty``
e. ``++*iter; // 合法，先把iter解參考，然後++string，string不給++``
f. ``iter++->empty(); //合法:等價於(*iter++).empty();
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

    return 0;
}