/*
- 練習7.37: 使用來自本節的Sales_data版本，判斷哪個建構器備用來初始化下列各個變數，並列出給個物件中資料成員的值:
```
Sales_data first_item(cin);

int main() {
    Sales_data next;
    Sales_data last("9-999-99999-9");
}
```
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Sales_data{
public:
    friend istream &read(istream&, Sales_data&);
    Sales_data(std::string s=""): bookNo(s){}
    Sales_data(std::string s, unsigned cnt, double rev):
        bookNo(s), units_sold(cnt), revenue(rev*cnt) {}
    Sales_data(std::istream &is) { read(is, *this);}
private:
	std::string bookNo;
	unsigned int units_sold = {0};
	double revenue = {0.0};

};
istream &read(istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}
Sales_data first_item(cin);
int main()
{
    Sales_data next;
    Sales_data last("9-999-99999-9");

    return 0;
}