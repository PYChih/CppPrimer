/*
練習2.41 使用你的Sales_data類別來改寫1.5.1、1.5.2和1.6中的練習。就現在來說，你應該將你的Sales_data類別定義在跟main函式相同的檔案中。
### 習題章節1.5.1:
- 練習1.20: 讀取一組書籍販售紀錄，再將每筆交易紀錄寫到標準輸出i.e. 讀寫
輸入: isbn number price;多筆 (book sales)
輸出: isbn number revenue average_price
- 練習1.21: 讀取兩個具有相同ISBN的Sales_item物件，並產生它們的總和。i.e. 合併(相加)
輸入: add_item
輸出: isbn number revenue average_price
- 練習1.22: 寫一個程式讀取具有相同ISBN的數筆交易紀錄。寫出所讀取的所有交易紀錄之總和。i.e. 相加多筆
輸入: isbn number price;多筆 (book sales)
輸出: isbn number revenue average_price
### 習題章節1.5.2: 
- 練習1.23: 寫一個程式，讀取數筆交易紀錄，併計數每個ISBN出現幾次。
輸入: isbn number price;多筆 (book sales)
輸出: isbn number
- 練習1.24: 給予前一個程式代表多個ISBN的多筆交易紀錄來測試它。每個ISBN的交易紀錄應該歸為同一組。
### 習題章節1.6:
- 練習1.25: 使用Sales_item.h標頭，編譯並執行本節中的書店程式。
    - 讀取銷售紀錄所組成的一個檔案，並產生一個報告，為每本書顯示售出的總本數、總營收，以及平均售價。
    - 假設輸出中每個ISBN的所有交易紀錄都被歸成一組。就是相同ISBN的交易紀錄被排好了。
    - 將每個ISBN的資料結合在名為total的一個變數中。
    - 用名為trans的第二個變數來存放讀取的每筆交易紀錄。
    - 如果trans和total指涉相同的ISBN，我們就更新total，否則，印出total，並使用我們剛讀取的交易紀錄來重設它。
/*
 * g++ exercise_2_42.cpp && ./a.out
 */
#include<iostream>
#include<string>
#include "Sales_data.h"

int main()
{
    // 1.5.1-1.20
    //Sales_data data1;
    //double price;
    //while (std::cin>> data1.bookNo >> data1.units_sold >> price)
    //    std::cout<<data1.bookNo<<" "<<data1.units_sold<<" "<<price<<std::endl;
    // g++ exercise_2_41.cpp && ./a.out <data/book_sales
    
    // 1.5.1-1.21
    //Sales_data data1, data2;
    //double price1, price2;
    //unsigned total_units_sold;
    //double total_revenue, average_price;
    //std::cin>> data1.bookNo >> data1.units_sold >> price1;
    //std::cin>> data2.bookNo >> data2.units_sold >> price2;
    ////std::cout<<data1.bookNo<<" "<<data1.units_sold<<" "<<price1<<std::endl;
    ////std::cout<<data2.bookNo<<" "<<data2.units_sold<<" "<<price2<<std::endl;
    //if (data1.bookNo == data2.bookNo){
    //    total_units_sold = data1.units_sold + data2.units_sold;
    //    total_revenue = data1.units_sold * price1 + data2.units_sold * price2;
    //    average_price = total_revenue / total_units_sold;
    //    std::cout<< data1.bookNo<<" "<< total_units_sold <<" "<<total_revenue<<" "<<average_price<<std::endl;
    //} else {
    //    std::cerr << "Data must refer to same ISBN." << std::endl;
	//	return -1;
    //}
    //g++ exercise_2_41.cpp && ./a.out <data/add_item
    //g++ exercise_2_41.cpp && ./a.out <data/book_sales : Data must refer to same ISBN.

    // 1.5.1-1.22, 1.5.2-1.23, 1.5.2-1.24 and 1.6-1.25
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