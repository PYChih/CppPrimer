#include "Book_14_08.h"
using std::ostream;
std::istream &read(std::istream &is, Book &item) {  // NOLINT
  is >> item.bookNo >> item.units_sold >> item.price;
  item.revenue = item.units_sold * item.price;
  return is;
}
ostream &operator<<(ostream &os, const Book &item) {
  os << "isbn : " << item.bookNo << " "
     << "unit sold : " << item.units_sold << " "
     << "price : " << item.price << " "
     << "revenue : " << item.revenue;
  return os;
}
