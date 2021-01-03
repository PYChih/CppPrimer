/*
- 練習7.42: 對於你為7.5.1的練習7.40所寫的類別，判斷其中是否有任何建構器可以使用委派。
若有，就為你的類別撰寫委派建構器。如果沒有，就看看抽象層的清單，選出一個你認為會使用委派建構器的。為那個抽象層撰寫類別定義
 */


#include <iostream>
#include <string>
#include <vector>
using namespace std;

class book{
public:
    friend istream& read(istream&is, book& item);
    book(const string &s, unsigned int n, double p): bookNo(s), units_sold(n), price_twd(p), revenue(n*p) {cout<<"I'm three param constructor";}
    book():book("", 0, 0){cout<<"I'm default constructor";}
    book(const string &s): bookNo(s) {}
    
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
    cout<<"book book1;"<<endl;
    book book1;
    return 0;
}