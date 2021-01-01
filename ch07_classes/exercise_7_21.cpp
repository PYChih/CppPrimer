/*
- 練習7.21: 更新你的Sales_data類別來隱藏其實作。你寫來使用Sales_data運算的那些程式應該都要能繼續運作。重新編譯帶有你的新類別定義的那些程式，驗證它們仍然可運行
g++ exercise_7_21.cpp && ./a.out <data/book_sales
 */

#include "Sales_data_7_2.h"
int main()
{
    if (cin){
        Sales_data total(cin);
        while (cin){
            Sales_data trans(cin);
            if (!cin){break;}
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