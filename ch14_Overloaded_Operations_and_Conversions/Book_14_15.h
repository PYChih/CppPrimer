#ifndef CH14_OVERLOADED_OPERATIONS_AND_CONVERSIONS_BOOK_14_15_H_
#define CH14_OVERLOADED_OPERATIONS_AND_CONVERSIONS_BOOK_14_15_H_
#include <string>
#include <iostream>
class Book {
  friend Book operator+(const Book &lhs, const Book &rhs);
  friend std::istream &read(std::istream &is, Book &item);  // NOLINT
  friend std::ostream &operator<<(std::ostream &os, const Book &item);
  friend std::istream &operator>>(std::istream &is, Book &item);
 public:
  Book() = default;
  Book(const std::string &s) : bookNo(s) {}  // NOLINT
  Book(const std::string &s, unsigned n, double p)
      : bookNo(s), units_sold(n), price(p) {
        revenue = price * units_sold;
      }
  Book &operator+=(const Book &rhs);
 private:
  std::string bookNo;
  unsigned units_sold;
  double price;
  double revenue;
};
std::istream &read(std::istream &is, Book &item);
std::istream &operator>>(std::istream &is, Book &item);
std::ostream &operator<<(std::ostream &os, const Book &item);
Book operator+(const Book &lhs, const Book &rhs);
#endif  // CH14_OVERLOADED_OPERATIONS_AND_CONVERSIONS_BOOK_14_15_H_
