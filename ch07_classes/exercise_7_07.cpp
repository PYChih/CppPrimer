/*
- 練習7.1: 為來自1.6的交易處理程式寫出另一個版本，使用你為2.6.1中練習所定義的Sales_data類別
### 習題章節1.6:
- 練習1.25: 使用Sales_item.h標頭，編譯並執行本節中的書店程式。
    - 讀取銷售紀錄所組成的一個檔案，並產生一個報告，為每本書顯示售出的總本數、總營收，以及平均售價。
    - 假設輸出中每個ISBN的所有交易紀錄都被歸成一組。就是相同ISBN的交易紀錄被排好了。
    - 將每個ISBN的資料結合在名為total的一個變數中。
    - 用名為trans的第二個變數來存放讀取的每筆交易紀錄。
    - 如果trans和total指涉相同的ISBN，我們就更新total，否則，印出total，並使用我們剛讀取的交易紀錄來重設它。
 */
// define read and print function 
// read(cin, total) -> cin
// print(cout<<total) -> cout

#include<iostream>
#include <string>
#include "Sales_data.h"
using namespace std;

int main()
{

    Sales_data book1, book2;
    double price1, price2;
    unsigned total_units_sold;
    double total_revenue;
    int accumulate_isbn;
    if (std::cin>> book1.bookNo >> book1.units_sold >> price1){
        total_units_sold = book1.units_sold;
        total_revenue = book1.units_sold * price1;
        accumulate_isbn = 1;
        while (std::cin>> book2.bookNo >> book2.units_sold >> price2){
            if (book1.bookNo==book2.bookNo){
                total_units_sold += book2.units_sold;
                total_revenue += book2.units_sold * price2;
                accumulate_isbn+=1;
            }else {
                std::cout<<book1.bookNo<<" "<<total_units_sold<<" "<<total_revenue<<" "<<(total_revenue / total_units_sold)<<std::endl;
                std::cout<<accumulate_isbn<<std::endl;
                book1.bookNo = book2.bookNo;
                total_units_sold = book2.units_sold;
                total_revenue = book2.units_sold * price2;
                accumulate_isbn = 1;
            }
        }
        std::cout<<book1.bookNo<<" "<<total_units_sold<<" "<<total_revenue<<" "<<(total_revenue / total_units_sold)<<std::endl;
        std::cout<<accumulate_isbn<<std::endl;
    }
    // g++ exercise_2_42.cpp && ./a.out <data/book_sales
    return 0;
}