//  Exercise 11.11:
//  Redefine bookstore without using decltype.

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

    return 0;
}
