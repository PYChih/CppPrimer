// Exercise 11.30:
// Explain the meaning of the operand pos.first->second used
// in the output expression of the final program in this section.
// first like lowerbound and second like upperbound
// if lowerbound != upperbound, increment lowerbound iterator
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
    map<string, string> authors{{"Alain de Botton", "Abook"}};
    string search_item("Alain de Botton"); //某個作者的名子
    for (auto pos = authors.equal_range(search_item);
         pos.first != pos.second; ++pos.first)
         cout<< pos.first->second << endl;
    return 0;
}