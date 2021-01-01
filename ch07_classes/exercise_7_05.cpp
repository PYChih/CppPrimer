/*
- 練習7.5: 在你的Person中提供運算來回傳人的名稱和地址。這些函式應該是const嗎? 解釋你的選擇
 */

#include <iostream>
#include <string>
using namespace std;

struct Person
{
	string name = "user_1";
	string address = "Taiwan";
    string getName() const {return name;}
    string getAddress() const {return address;}
};

int main()
{
    Person p1;
    cout << "p1 name : " << p1.getName() << " ; "
         << "p1 address : " << p1.getAddress() << endl;
    return 0;
}