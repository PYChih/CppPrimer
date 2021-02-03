#ifndef CH14_OVERLOADED_OPERATIONS_AND_CONVERSIONS_BOOK_14_08_H_
#define CH14_OVERLOADED_OPERATIONS_AND_CONVERSIONS_BOOK_14_08_H_
#include <string>
#include <iostream>
class Book {
  friend std::istream &read(std::istream &is, Book &item);  // NOLINT
  friend std::ostream &operator<<(std::ostream &os, const Book &item);
 public:
  Book() = default;
  Book(const std::string &s) : bookNo(s) {}  // NOLINT
  Book(const std::string &s, unsigned n, double p)
      : bookNo(s), units_sold(n), price(p) {
        revenue = price * units_sold;
      }
 private:
  std::string bookNo;
  unsigned units_sold;
  double price;
  double revenue;
};
std::istream &read(std::istream &is, Book &item);
std::ostream &operator<<(std::ostream &os, const Book &item);
#endif  // CH14_OVERLOADED_OPERATIONS_AND_CONVERSIONS_BOOK_14_08_H_
