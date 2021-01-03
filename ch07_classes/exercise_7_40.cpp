/*
- 練習7.40: 選擇下列的抽象層(abstractions)之一(或你自己找的抽象層)。判斷該類別中需要什麼資料。提供適當的一組建構器。解釋你的決策。
```
a book
b. Date
c. Employee
d. Vehicle
e. object
f. tree
```
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class book{
public:
    friend istream& read(istream&is, book& item);
    book() = default;
    book(const string &s): bookNo(s) {}
    book(const string &s, unsigned int n, double p): bookNo(s), units_sold(n), price_twd(p) {}
    book(istream &);
private:
    string bookNo;
    unsigned int units_sold = {0};
    double price_twd = 0;
    double revenue = 0;
};
istream& read(istream & is, book & item)
{
    is >> item.bookNo >> item.units_sold >> item.price_twd;
    item.revenue = item.units_sold * item.price_twd;
    return is;
}
book::book(istream &is){
    read(is, *this);
}
int main()
{
    book book1;
    return 0;
}