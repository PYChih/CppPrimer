/*
- 練習7.45: 如果我們把前一個練習中的vector定義為存放型別為C的物件，那會怎樣?
``//合法喔``
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class NoDefault {
public:
    NoDefault(int);
private:
    int imintmember;
};
NoDefault::NoDefault(int ival):imintmember(ival){cout<<"I'm int constructor";}
class C_class{
    //C_class()=default;
public:
    C_class(int i=1):imnodefaultmember(i){}
private:
    NoDefault imnodefaultmember;
};

int main()
{
    C_class Citem;
    vector<C_class> vec(10);
    return 0;
}