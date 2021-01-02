/*
- 練習7.39: 讓接受一個string和接受一個istream&的兩個建構器都有預設引數是合法的嗎?若非，為何呢? // 非法，函式重載不明確
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Sales_data{
public:
    friend istream &read(istream&, Sales_data&);
    Sales_data(std::string s): bookNo(s){}
    Sales_data(std::string s, unsigned cnt, double rev):
        bookNo(s), units_sold(cnt), revenue(rev*cnt) {}
    Sales_data(std::istream &is=cin) { read(is, *this);}
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