#include "Book_14_15.h"
using std::ostream;
using std::istream;
istream &read(istream &is, Book &item) {  // NOLINT
  is >> item.bookNo >> item.units_sold >> item.price;
  item.revenue = item.units_sold * item.price;
  return is;
}
istream &operator>>(istream &is, Book &item) {
  is >> item.bookNo >> item.units_sold >> item.price;
  if (is) {
    item.revenue = item.units_sold * item.price;
  } else {
    item = Book();
  }
  return is;
}
ostream &operator<<(ostream &os, const Book &item) {
  os << "isbn : " << item.bookNo << " "
     << "unit sold : " << item.units_sold << " "
     << "price : " << item.price << " "
     << "revenue : " << item.revenue;
  return os;
}
Book &Book::operator+=(const Book &rhs) {
  // if same isbn
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  price = revenue / units_sold;
  return *this;
}
Book operator+(const Book &lhs, const Book &rhs) {
  Book sum = lhs;
  sum += rhs;
  return sum;
}
