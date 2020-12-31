/*
- 練習7.3: 修改$7.1.1你寫的交易處理程式，使用那些成員
g++ exercise_7_07.cpp && ./a.out <data/book_sales
 */

#include <iostream>
#include <string>
#include "Sales_data_7_1_3.h"
using namespace std;

int main()
{
    Sales_data total;
    double total_price;
    unsigned total_units_sold;
    if (read(cin, total)){
        Sales_data trans;
        double trans_price;
        while (read(cin, trans)){
            if (total.isbn() == trans.isbn()){
                total = total.combine(trans);
            }else {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    }
    return 0;
}