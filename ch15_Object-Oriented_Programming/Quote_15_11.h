#ifndef CH15_OBJECT_ORIENTED_PROGRAMMING_QUOTE_15_11_H_
#define CH15_OBJECT_ORIENTED_PROGRAMMING_QUOTE_15_11_H_
#include <iostream>
#include <string>
#include <cstddef>
class Quote {
 public:
  Quote() = default;
  Quote(const std::string &book, double sales_price)
      : bookNo(book), price(sales_price) { }
  std::string isbn() const { return bookNo; }
  virtual double net_price(std::size_t n) const {
    return n * price;
  }
  virtual std::ostream &debug(std::ostream &os) const;
  virtual ~Quote() = default;
 private:
  std::string bookNo;
 protected:
  double price = 0.0;
};
class Bulk_quote : public Quote {
 public:
  Bulk_quote() = default;
  Bulk_quote(const std::string &book, double p, std::size_t qty, double disc);
  double net_price(std::size_t cnt) const override;
  std::ostream &debug(std::ostream &os) const override;
 private:
  std::size_t min_qty = 0;
  double discount = 0.0;
};
double print_total(std::ostream &os, const Quote &item, std::size_t n);
#endif  // CH15_OBJECT_ORIENTED_PROGRAMMING_QUOTE_15_11_H_