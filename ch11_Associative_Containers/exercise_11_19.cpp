// Exercise 11.19:
// Define a variable that you initialize by calling begin() on the multiset named bookstore from 11.2.2 (11,11). Write the variable’s type without using auto or decltype.
//          Exercise 11.11:
//          Redefine bookstore without using decltype.

# include<iostream>
# include<string>
using namespace std;
# include"Sales_data.h"

#include<algorithm>
#include<set>
#include <map>

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() < rhs.isbn();
}

int main(){
    using less_Isbn = bool (*) (Sales_data const&, Sales_data const&);
    multiset<Sales_data, less_Isbn> bookstore(compareIsbn);
    multiset<Sales_data, less_Isbn>::iterator book_it = bookstore.begin();
    return 0;
}