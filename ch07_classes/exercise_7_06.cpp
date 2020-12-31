/*
- 練習7.6: 定義你自己版本的add、read與print函式
 */

#include <iostream>
#include <string>

using namespace std;

struct Sales_data
{
    std::string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);
    double avg_price() const {
        if (units_sold)
            return revenue/units_sold;
        else
        {
            return 0;
        }
        
    }
	std::string bookNo;
	unsigned int units_sold = {0};
	double revenue = {0.0};
};
Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this; //回傳在其上這個函式被呼叫的那個物件
}
istream &read(istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}
ostream &print(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();
    return os;
}
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

int main()
{
    Sales_data item;
    return 0;
}