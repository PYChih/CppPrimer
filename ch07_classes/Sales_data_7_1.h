#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
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
#endif