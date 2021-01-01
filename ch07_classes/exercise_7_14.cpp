/*
- 練習7.14: 寫出另一個版本的預設建構器，讓它將那些成員明確的初始化為我們提供做為類別內初始器的那些值。
 */
#include <iostream>
#include <string>
using namespace std;
struct Sales_data;
istream & read(istream &, Sales_data &);
struct Sales_data
{
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
int main()
{
    if (cin){
        Sales_data total(cin);
        while (cin){
            Sales_data trans(cin);
            if (total.isbn() == trans.isbn()){
                total = total.combine(trans);
            }else {
                print(cout, total) << endl;
                total = trans;
            }
        }
        //print(cout, total) << endl;
    }
    return 0;
}