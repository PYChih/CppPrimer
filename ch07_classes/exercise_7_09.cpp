/*
- 練習7.9: 為你在7.1.2練習中所寫的程式碼新增能夠讀取和印出Person物件的運算。
    - 練習7.4: 撰寫一個名為Person的類別，代表一個人的名稱和地址。使用一個string來存放那些元素。後續的練習會逐步新增功能到這個類別 
    - 練習7.5: 在你的Person中提供運算來回傳人的名稱和地址。這些函式應該是const嗎? 解釋你的選擇
 */

#include <iostream>
#include <string>
using namespace std;

struct Person
{
    // member data
	std::string name;
	std::string address;
    // member function
    std::string printName() const {return name;}
    std::string printAddress() const {return address;}
};
istream& read(istream & is, Person& ps)
{
    is >> ps.name >> ps.address;
    return is;
}
ostream& print(ostream &os, const Person& ps)
{
    os << ps.name << ps.address;
    return os;
}

int main()
{
    return 0;
}