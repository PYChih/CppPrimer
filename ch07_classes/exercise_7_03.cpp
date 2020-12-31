/*
- 練習7.3: 修改$7.1.1你寫的交易處理程式，使用那些成員
 */

#include <iostream>
#include <string>
#include "Sales_data_7_1.h"
using namespace std;

int main()
{
    Sales_data total;
    double total_price;
    unsigned total_units_sold;
    int accumulate_isbn;
    if (cin >> total.bookNo >> total.units_sold >> total_price){
        total.revenue = total.units_sold * total_price;
        accumulate_isbn = 1;
        Sales_data trans;
        double trans_price;
        while (cin >> trans.bookNo >> trans.units_sold >> trans_price){
            trans.revenue = trans.units_sold * trans_price;
            if (total.isbn() == trans.isbn()){
                total = total.combine(trans);
                accumulate_isbn+=1;
            }else {
                cout << "isbn : " <<total.isbn() << " " 
                     << total.units_sold << " " << total.revenue
                     << " " << (total.revenue / total.units_sold) << endl;
                total.bookNo = trans.bookNo;
                total.units_sold = trans.units_sold;
                total.revenue = trans.revenue;
                accumulate_isbn = 1;
            }
        }
        cout << "isbn : " <<total.isbn() << " " 
             << total.units_sold << " " << total.revenue
             << " " << (total.revenue / total.units_sold) << endl;
    }
    return 0;
}