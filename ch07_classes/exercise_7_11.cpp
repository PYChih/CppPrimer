/*
- 練習7.11: 為你的Sales_data類別新增建構器，並寫一個程式來使用那每一個建構器。
 */
#include <string>
#include <iostream>
using namespace std;
struct Sales_data
{
    //constructors
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s){}
    Sales_data(const std::string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n){}
    Sales_data(std::istream &);
    //members
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
std::istream &read(std::istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}
std::ostream &print(std::ostream &os, const Sales_data &item)
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
Sales_data::Sales_data(std::istream & is){
    read(is, *this);
}
int main(){
    cout << "default constructor"<<endl;
    Sales_data item_default;
    print(cout, item_default)<<endl;
    cout << "isbn only"<<endl;
    Sales_data item_isbn("99999");
    print(cout, item_isbn)<<endl;
    cout << "isbn, units_sold, price"<<endl;
    Sales_data item("11111", 10, 9);
    print(cout, item)<<endl;
    cout << "cin item" << endl;
    Sales_data cinitem(cin);
    print(cout, cinitem)<< endl;
}