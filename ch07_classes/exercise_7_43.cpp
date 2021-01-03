/*
- 練習7.43: 假設我們有一個名為NoDefault的類別，它有一個接受一個int的建構器，但沒有預設建構器。定義一個類別C，其中具有型別為NoDefault的一個成員。為C定義預設建構器
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class NoDefault {
public:
    NoDefault(int);
private:
    int imintmember=0;
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
    return 0;
}