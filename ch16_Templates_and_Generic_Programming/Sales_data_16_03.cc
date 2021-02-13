#include "Sales_data_16_03.h"  // NOLINT
using std::string;
using std::cout;
using std::endl;
using std::ostream;
using std::istream;
using std::initializer_list;
// Sales_data::operator double() const {
//   return revenue;
// }
Sales_data::operator string() const {
  return bookNo;
}

Sales_data &Sales_data::operator=(const string &s) {
  *this = Sales_data(s);
  return *this;
}
Sales_data &Sales_data::combine(const Sales_data &rhs) {
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}
istream &read(istream &is, Sales_data &item) {  // NOLINT
  double price = 0;
  is >> item.bookNo >> item.units_sold >> price;
  item.revenue = price * item.units_sold;
  return is;
}
ostream &print(ostream &os, const Sales_data &item) {
  os << "isbn : " << item.isbn() << " "
     << "unit sold : " << item.units_sold << " "
     << "revenue : " << item.revenue << " "
     << "average price : " << item.avg_price();
  return os;
}
Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
  Sales_data sum = lhs;
  sum.combine(rhs);
  return sum;
}
ostream &operator<<(ostream &os, const Sales_data &item) {
  os << "isbn : " << item.isbn() << " "
     << "unit sold : " << item.units_sold << " "
     << "revenue : " << item.revenue << " "
     << "average price : " << item.avg_price();
  return os;
}
istream &operator>>(istream &is, Sales_data &item) {
  double price;
  is >> item.bookNo >> item.units_sold >> price;
  if (is) {
    item.revenue = price * item.units_sold;
  } else {
    item = Sales_data();
  }
  return is;
}
Sales_data& Sales_data::operator+=(const Sales_data &rhs) {
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}
Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
  Sales_data sum = lhs;
  sum += rhs;
  return sum;
}
