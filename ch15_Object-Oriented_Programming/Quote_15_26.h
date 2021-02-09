#ifndef CH15_OBJECT_ORIENTED_PROGRAMMING_QUOTE_15_26_H_
#define CH15_OBJECT_ORIENTED_PROGRAMMING_QUOTE_15_26_H_
#include <iostream>
#include <string>
#include <cstddef>
#include <utility>
class Quote {
  friend bool operator!=(const Quote &lhs, const Quote &rhs);

 public:
  // default constructor
  Quote() : bookNo(""), price(0.0) {
    std::cout << "I'm Quote default constructor" << std::endl;
  }
  Quote(const std::string &book, double sales_price)
      : bookNo(book), price(sales_price) { }
  std::string isbn() const { return bookNo; }
  // copy constructor
  Quote(const Quote &qt) : bookNo(qt.bookNo),
      price(qt.price) {
    std::cout << "I'm Quote copy constructor" << std::endl;
  }
  // move constructor
  Quote(Quote &&qt) noexcept : bookNo(std::move(qt.bookNo)),
      price(std::move(qt.price)) {
    std::cout << "I'm Quote move constructor" << std::endl;
  }
  // copy assignment operator
  Quote &operator=(const Quote &rhs) {
    if (*this != rhs) {
      bookNo = rhs.bookNo;
      price = rhs.price;
    }
    std::cout << "I'm Quote copy assignment operator" << std::endl;
    return *this;
  }
  // move assignment operator
  Quote &operator=(Quote &&rhs) noexcept {
    if (*this != rhs) {
      bookNo = std::move(rhs.bookNo);
      price = std::move(rhs.price);
    }
    std::cout << "I'm Quote move assignment operator" << std::endl;
    return *this;
  }
  virtual double net_price(std::size_t n) const {
    return n * price;
  }
  virtual std::ostream &debug(std::ostream &os) const;
  // destructor
  // virtual ~Quote() {
  ~Quote() {
    std::cout << "I'm Quote destructor" << std::endl;
  }

 private:
  std::string bookNo;

 protected:
  double price = 0.0;
};
class Disc_quote : public Quote {
  friend bool operator!=(const Disc_quote &lhs, const Disc_quote &rhs);

 public:
  Disc_quote() : Quote() {
    std::cout<< "I'm Disc_quote default constructor" << std::endl;
  }
  Disc_quote(const std::string &book, double price,
             std::size_t qty, double disc)
             : Quote(book, price),
             quantity(qty), discount(disc) { }
  double net_price(std::size_t) const = 0;
  // copy constructor
  Disc_quote(const Disc_quote &dq) : Quote(dq), quantity(dq.quantity),
      discount(dq.discount) {
    std::cout << "I'm Disc_quote copy constructor" << std::endl;
  }
  // move constructor
  Disc_quote(Disc_quote &&dq) noexcept : Quote(std::move(dq)),
      quantity(std::move(dq.quantity)), discount(std::move(dq.discount)) {
    std::cout << "I'm Disc_quote move constructor" << std::endl;
  }
  // copy assignment operator
  Disc_quote &operator=(const Disc_quote &rhs) {
    Quote::operator=(rhs);
    this->quantity = rhs.quantity;
    this->discount = rhs.discount;
    std::cout << "I'm Disc_quote copy assignment operator" << std::endl;
    return *this;
  }
  // move assignment operator
  Disc_quote &operator=(Disc_quote &&rhs) noexcept {
    if (*this != rhs) {
      Quote::operator=(std::move(rhs));
      this->quantity = std::move(rhs.quantity);
      this->discount = std::move(rhs.discount);
    }
    std::cout << "I'm Dis_quote move assignment operator" << std::endl;
    return *this;
  }
  // virtual ~Disc_quote() {
  ~Disc_quote() {
    std::cout << "I'm Disc_quote destructor" << std::endl;
  }

 protected:
  std::size_t quantity = 0;
  double discount = 0.0;
};
class Bulk_quote : public Disc_quote {
  friend bool operator!=(const Bulk_quote &rhs, const Bulk_quote &lhs);

 public:
  // default constructor
  Bulk_quote() : Disc_quote() {
    std::cout << "I'm Bulk_quote default constructor" << std::endl;
  }
  Bulk_quote(const std::string &book, double price,
             std::size_t qty, double disc)
             : Disc_quote(book, price, qty, disc) { }
  double net_price(std::size_t) const override;
  // copy constructor
  Bulk_quote(const Bulk_quote &bq) : Disc_quote(bq) {
    std::cout << "I'm Bulk_quote copy constructor" << std::endl;
  }
  // move constructor
  Bulk_quote(Bulk_quote &&bq) : Disc_quote(std::move(bq)) {
    std::cout << "I'm Bulk_quote move constructor" << std::endl;
  }
  // copy assignment operator
  Bulk_quote &operator=(const Bulk_quote &rhs) {
    Quote::operator=(rhs);
    std::cout << "I'm Bulk_quote copy assignment operator" << std::endl;
    return *this;
  }
  Bulk_quote &operator=(Bulk_quote &&rhs) {
    if (*this != rhs) {
    Quote::operator=(std::move(rhs));
    }
    std::cout << "I'm Bulk_quote move assignment operator" << std::endl;
    return *this;
  }
  ~Bulk_quote() {
    std::cout << "I'm Bulk_quote destructor" << std::endl;
  }
  std::ostream &debug(std::ostream &os) const;
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
bool operator!=(const Quote &lhs, const Quote &rhs);
bool operator!=(const Disc_quote &lhs, const Disc_quote &rhs);
bool operator!=(const Bulk_quote &lhs, const Bulk_quote &rhs);
#endif  // CH15_OBJECT_ORIENTED_PROGRAMMING_QUOTE_15_26_H_