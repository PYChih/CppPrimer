#include <iostream>
#include <string>
using namespace std;
#ifndef SALES_DATA_H
#define SALES_DATA_H
class Sales_data
{
    friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
    friend ostream &print(ostream &os, const Sales_data &item);
    friend istream &read(istream &is, Sales_data &item);
    public:
    Sales_data(): bookNo(""), units_sold(0), revenue(0){}
    Sales_data(const string &s) : bookNo(s) {}
    Sales_data(const string &s, unsigned n, double p):
        bookNo(s), units_sold(n), revenue(p*n) { }
    Sales_data(istream &is){read(is, *this);}
    string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);
    double avg_price() const {
        if (units_sold)
            return revenue/units_sold;
        else
        {
            return 0;
        }
    }
    private:
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
    os << "isbn : " <<item.isbn() << " " 
         << "unit sold : " << item.units_sold << " "
         << "revenue : "<< item.revenue << " "
         << "average price : " << item.avg_price();
    return os;
}
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}
#endif