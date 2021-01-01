/*
- 練習7.3: 修改$7.1.1你寫的交易處理程式，使用那些成員
g++ exercise_7_03.cpp && ./a.out <data/book_sales
 */

#include <iostream>
#include "Sales_data_7_1.h"
using namespace std;

int main()
{
    Sales_data total;
    double total_price;
    unsigned total_units_sold;
    if (cin >> total.bookNo >> total.units_sold >> total_price){
        total.revenue = total.units_sold * total_price;
        Sales_data trans;
        double trans_price;
        while (cin >> trans.bookNo >> trans.units_sold >> trans_price){
            trans.revenue = trans.units_sold * trans_price;
            if (total.isbn() == trans.isbn()){
                total = total.combine(trans);
            }else {
                cout << "isbn : " <<total.isbn() << " " 
                     << "unit sold : " << total.units_sold << " "
                     << "revenue : "<< total.revenue << " "
                     << "average price : " << total.avg_price() << endl;
                total.bookNo = trans.bookNo;
                total.units_sold = trans.units_sold;
                total.revenue = trans.revenue;
            }
        }
        cout << "isbn : " <<total.isbn() << " " 
             << "unit sold : " << total.units_sold << " "
             << "revenue : "<< total.revenue << " "
             << "average price : " << total.avg_price() << endl;
    }
    return 0;
}