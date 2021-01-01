/*
- 練習7.15: 新增適當的建構器到你的Person類別中
    - 練習7.4: 撰寫一個名為Person的類別，代表一個人的名稱和地址。使用一個string來存放那些元素。後續的練習會逐步新增功能到這個類別 
    - 練習7.5: 在你的Person中提供運算來回傳人的名稱和地址。這些函式應該是const嗎? 解釋你的選擇
    - 練習7.9: 為你在7.1.2練習中所寫的程式碼新增能夠讀取和印出Person物件的運算。
 */

#include <iostream>
#include <string>
using namespace std;

struct Person;
istream& read(istream &, Person&);
struct Person
{
    //Constructor
    Person() = default;
    Person(istream & is){read(is, *this);}
    // member data
	string name;
	string address;
    // member function
    string printName() const {return name;}
    string printAddress() const {return address;}
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
    cout << "default constructor"<<endl;
    Person p1;
    print(cout, p1)<<endl;
    while(cin){
        Person p2(cin);
        if (!cin){break;}
        print(cout, p2)<<endl;
    }
    return 0;
}