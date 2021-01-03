/*
- 練習7.44: 下列的宣告是合法的嗎?如果不是，為什麼呢?
``vector<NoDefault> vec(10);//主要就是像在vector<NoDefault>宣告的時候，vec(10)會用NoDefault的預設建構器來初始化，可是因為沒有預設建構器，所以就不會初始化了``
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
    vector<NoDefault> vec(10);
    return 0;
}