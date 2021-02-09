#include "Quote_15_27.h"
using std::ostream;
using std::string;
using std::size_t;
using std::endl;
bool operator!=(const Bulk_quote &lhs, const Bulk_quote &rhs) {
  return Quote(lhs) != Quote(rhs) &&
         lhs.quantity != rhs.quantity &&
         lhs.discount != rhs.discount;
}
bool operator!=(const Disc_quote &lhs, const Disc_quote &rhs) {
  return Quote(lhs) != Quote(rhs) &&
         lhs.quantity != rhs.quantity &&
         lhs.discount != rhs.discount;
}
bool operator!=(const Quote &lhs, const Quote &rhs) {
  return lhs.bookNo != rhs.bookNo &&
         lhs.price != rhs.price;
}
double Bulk_quote::net_price(size_t cnt) const {
  if (cnt >= quantity)
    return cnt * (1 - discount) * price;
  else
    return cnt * price;
}
double print_total(ostream &os, const Quote &item, size_t n) {
  double ret = item.net_price(n);
  os << "ISBN: " << item.isbn()
     << " # sold: " << n << " total due: " << ret << endl;
  return ret;
}
ostream &Quote::debug(ostream &os) const {
  os << "base version" << endl;
  os << "bookNo : " << bookNo
     << " price : " << price;
  return os;
}
ostream &Bulk_quote::debug(ostream &os) const {
  os << "derived version" << endl;
  os << "bookNo : " << isbn()
     << " price " << price << endl
     << "discount " << discount
     << " if unit_sold greater than "
     << quantity;
  return os;
}