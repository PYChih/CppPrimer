#ifndef CH15_OBJECT_ORIENTED_PROGRAMMING_EXERCISE_15_07_H_
#define CH15_OBJECT_ORIENTED_PROGRAMMING_EXERCISE_15_07_H_
#include <iostream>
#include <string>
#include <cstddef>
class Quote {
 public:
  Quote() = default;
  Quote(const std::string &book, double sales_price)
      : bookNo_(book), price_(sales_price) { }
  std::string isbn() const { return bookNo_; }
  virtual double net_price(std::size_t n) const {
    return n * price_;
  }
  virtual ~Quote() = default;
 private:
  std::string bookNo_;
 protected:
  double price_ = 0.0;
};
class Bulk_quote : public Quote {
 public:
  Bulk_quote() = default;
  Bulk_quote(const std::string &book, double p,
             std::size_t min_qty, std::size_t max_qty,
             double disc);
  double net_price(std::size_t cnt) const override;
 private:
  std::size_t min_qty_ = 0;
  std::size_t max_qty_ = 0;
  double discount_ = 0.0;
};
double print_total(std::ostream &os, const Quote &item, std::size_t n);
#endif  // CH15_OBJECT_ORIENTED_PROGRAMMING_EXERCISE_15_07_H_