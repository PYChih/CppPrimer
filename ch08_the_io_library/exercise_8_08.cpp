/*
- 練習8.8: 修改上一個練習的程式，將其輸出附加到給定的檔案。在同一個輸出檔上執行這個程式至少兩次，以確保資料有被保留。

g++ exercise_8_08.cpp && ./a.out data/book_sales data/output_book_sales2
- 練習8.7: 修改前一節的書店程式，將其輸出寫到一個檔案。將該檔案的名稱作為main的第二個引數傳入。
- 練習8.6: 改寫$7.1.1的書店程式，從一個檔案讀取其交易紀錄。將檔案的名稱作為一個引數傳入給main
- 練習7.1: 為來自1.6的交易處理程式寫出另一個版本，使用你為2.6.1中練習所定義的Sales_data類別
- 練習1.25: 使用Sales_item.h標頭，編譯並執行本節中的書店程式。
    - 讀取銷售紀錄所組成的一個檔案，並產生一個報告，為每本書顯示售出的總本數、總營收，以及平均售價。
    - 假設輸出中每個ISBN的所有交易紀錄都被歸成一組。:=就是相同ISBN的交易紀錄被排好了。
    - 將每個ISBN的資料結合在名為total的一個變數中。
    - 用名為trans的第二個變數來存放讀取的每筆交易紀錄。
    - 如果trans和total指涉相同的ISBN，我們就更新total，否則，印出total，並使用我們剛讀取的交易紀錄來重設它。
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "Sales_data.h"


int main(int argc, char *argv[])
{
    cout<<"argv[0] is : "<<argv[0]<<endl;
    cout<<"argv[1] is : "<<argv[1]<<endl;
    cout<<"argv[2] is :"<<argv[2]<<endl;
    cout<<"argc is : "<<argc<<endl;
    ifstream in(argv[1]);
    ofstream out(argv[2], ofstream::app);
    Sales_data total;
    double total_price;
    unsigned total_units_sold;
    double total_revenue;
    int accumulate_isbn;
    if (in >> total.bookNo >> total.units_sold >> total_price){
        total_units_sold = total.units_sold;
        total_revenue = total.units_sold * total_price;
        accumulate_isbn = 1;
        Sales_data trans;
        double trans_price;
        while (in >> trans.bookNo >> trans.units_sold >> trans_price){
            if (total.bookNo == trans.bookNo){
                total_units_sold += trans.units_sold;
                total_revenue += trans.units_sold * trans_price;
                accumulate_isbn+=1;
            }else {
                out << "isbn : " <<total.bookNo << " " 
                     << total_units_sold << " " << total_revenue
                     << " " << (total_revenue / total_units_sold) << endl;
                total.bookNo = trans.bookNo;
                total_units_sold = trans.units_sold;
                total_revenue = trans.units_sold * trans_price;
                accumulate_isbn = 1;
            }
        }
        out << "isbn : " <<total.bookNo << " " 
             << total_units_sold << " " << total_revenue
             << " " << (total_revenue / total_units_sold) << endl;
    }
    return 0;
}