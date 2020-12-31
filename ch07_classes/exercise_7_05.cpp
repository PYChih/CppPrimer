/*
- 練習7.5: 在你的Person中提供運算來回傳人的名稱和地址。這些函式應該是const嗎? 解釋你的選擇
 */

#include <iostream>
#include <string>
using namespace std;

struct Person
{
	std::string name;
	std::string address;
    std::string printName() const {return name;}
    std::string printAddress() const {return address;}
};

int main()
{
    return 0;
}