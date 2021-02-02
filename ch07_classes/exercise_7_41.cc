// Exercise 7.41
//    改寫你自己版本的Sales_data類別，改為使用委派建構器。
//    新增一個述句到每個建構器的主體，讓它們在被執行的時候印出一個訊息。
//    盡可能以所有方式寫出宣告來建構一個Sales_data物件。
//    研究輸出，直到你確信你了解委派建構器之間的執行順序為止。
// g++ -c Sales_data_7_41.cc exercise_7_41.cc
// g++ Sales_data_7_41.o exercise_7_41.o && ./a.out

#include "Sales_data_7_41.h"
using std::endl;
using std::cout;
using std::cin;
int main() {
  cout << "default construct item1: " << endl;
  Sales_data item1;
  cout << "three params construct item2:" << endl;
  Sales_data item2("s", 1, 1);
  cout << "single string construct item3:" << endl;
  Sales_data item3("s");
  cout << "os construct item4:" << endl;
  Sales_data item4(cin);
  cout << "print" << endl;
  print(cout, item1) << endl;
  print(cout, item2) << endl;
  print(cout, item3) << endl;
  print(cout, item4) << endl;
    return 0;
}
