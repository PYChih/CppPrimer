/*
- 練習7.55: $7.5.5的data類別是一個字面值類別嗎? 如果不是，為何呢? 如果是，請解釋為什麼它是
``資料成員全都是字面值型別的彙總類別是字面值型別，data是彙總類別，但string不是字面值型別``
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// data is an aggregate class
struct Data { 
    int ival;
    string s;
};

int main()
{

    //constexpr Data d;// a constexpr variable must have a literal type or a reference type
    Data d{1," "}; 
    cout<<d.ival<<endl;
    cout<<d.s<<endl;
    return 0;
}