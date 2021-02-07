#include "exercise_15_07.h"  // NOLINT
using std::ostream;
using std::string;
using std::size_t;
using std::cout;
using std::endl;
Bulk_quote::Bulk_quote(const string &book, double p,
                       size_t min_qty, size_t max_qty,
                       double disc)
    : Quote(book, p), min_qty_(min_qty), max_qty_(max_qty), discount_(disc) { }
double Bulk_quote::net_price(size_t cnt) const {
  if (cnt >= min_qty_ && cnt <= max_qty_) {
    return cnt * (1 - discount_) * price_;
  } else if (cnt > max_qty_) {
    return max_qty_ * (1 - discount_) * price_ +
           (cnt - max_qty_) * price_;
  } else {
    return cnt * price_;
  }
}
double print_total(ostream &os, const Quote &item, size_t n) {
  double ret = item.net_price(n);
  os << "ISBN: " << item.isbn()
     << " # sold: " << n << " total due: " << ret << endl;
  return ret;
}
int main() {
  Quote base("999-999", 10);
  Bulk_quote derived("999-999", 10, 100, 200, 0.1);
  print_total(cout, base, 100);
  print_total(cout, derived, 100);
  print_total(cout, derived, 300);
}
