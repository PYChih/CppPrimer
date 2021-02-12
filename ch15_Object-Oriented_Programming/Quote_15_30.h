#ifndef CH15_OBJECT_ORIENTED_PROGRAMMING_QUOTE_15_30_H_
#define CH15_OBJECT_ORIENTED_PROGRAMMING_QUOTE_15_30_H_
#include <iostream>
#include <string>
#include <cstddef>
#include <utility>
class Quote {
 public:
  // default constructor
  Quote() : bookNo(""), price(0.0) { }
  Quote(const std::string &book, double sales_price)
      : bookNo(book), price(sales_price) { }
  std::string isbn() const { return bookNo; }
  virtual double net_price(std::size_t n) const {
    return n * price;
  }
  virtual std::ostream &debug(std::ostream &os) const;
  // destructor
  virtual ~Quote() { }
  //   std::cout << "I'm Quote destructor" << std::endl;
  // }
  virtual Quote* clone() const & { return new Quote(*this); }
  virtual Quote* clone() && { return new Quote(std::move(*this)); }

 private:
  std::string bookNo;

 protected:
  double price = 0.0;
};
class Disc_quote : public Quote {
 public:
  Disc_quote() : Quote() { }
  Disc_quote(const std::string &book, double price,
             std::size_t qty, double disc)
             : Quote(book, price),
             quantity(qty), discount(disc) { }
  double net_price(std::size_t) const = 0;
  // virtual ~Disc_quote() { }
  //   std::cout << "I'm Disc_quote destructor" << std::endl;
  // }

 protected:
  std::size_t quantity = 0;
  double discount = 0.0;
};
class Bulk_quote : public Disc_quote {
 public:
  // default constructor
  // Bulk_quote() : Disc_quote() { }  // inherit is not user define
  // Bulk_quote(const std::string &book, double price,
  //            std::size_t qty, double disc)
  //            : Disc_quote(book, price, qty, disc) { }
  using Disc_quote::Disc_quote;  // inherit from the direct base class;
  double net_price(std::size_t) const override;
  // ~Bulk_quote() { }
  //   std::cout << "I'm Bulk_quote destructor" << std::endl;
  // }
  std::ostream &debug(std::ostream &os) const;
  Bulk_quote *clone() const & { return new Bulk_quote(*this); }
  Bulk_quote *clone() && { return new Bulk_quote(*this); }
};
class Limit_quote : public Disc_quote {
 public:
  Limit_quote() = default;
  Limit_quote(const std::string &book, double price,
             std::size_t qty, double disc)
             : Disc_quote(book, price, qty, disc) { }
  double net_price(std::size_t n) const override {
    return n * price * (n < quantity ? 1 - discount : 1);
  }
};
double print_total(std::ostream &os, const Quote &item, std::size_t n);
#endif  // CH15_OBJECT_ORIENTED_PROGRAMMING_QUOTE_15_30_H_