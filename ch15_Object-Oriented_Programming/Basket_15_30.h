#ifndef CH15_OBJECT_ORIENTED_PROGRAMMING_BASKET_15_30_H_
#define CH15_OBJECT_ORIENTED_PROGRAMMING_BASKET_15_30_H_
#include <iostream>
#include <memory>
#include <set>
#include <utility>
#include "Quote_15_30.h"
class Basket {
 public:
  void add_item(const Quote &sale) {
    items.insert(std::shared_ptr<Quote>(sale.clone()));
  }
  void add_item(Quote &&sale) {
    items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
  }
  double total_receipt(std::ostream &os) const;

 private:
  static bool compare(const std::shared_ptr<Quote> &lhs,
                      const std::shared_ptr<Quote> &rhs) {
    return lhs->isbn() < rhs->isbn();
  }
  std::multiset<std::shared_ptr<Quote>, decltype(compare)*>
               items{compare};
};
#endif  // CH15_OBJECT_ORIENTED_PROGRAMMING_BASKET_15_30_H_