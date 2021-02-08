#include "Quote_15_11.h"
using std::ostream;
using std::string;
using std::size_t;
using std::endl;
Bulk_quote::Bulk_quote(const string &book, double p,
                       size_t qty, double disc)
    : Quote(book, p), min_qty(qty), discount(disc) { }
double Bulk_quote::net_price(size_t cnt) const {
  if (cnt >= min_qty)
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
     << min_qty;
  return os;
}