#ifndef CH14_OVERLOADED_OPERATIONS_AND_CONVERSIONS_BOOK_14_49_H_
#define CH14_OVERLOADED_OPERATIONS_AND_CONVERSIONS_BOOK_14_49_H_
#include <string>
#include <iostream>
class Book {
  friend Book operator+(const Book &lhs, const Book &rhs);
  friend std::istream &read(std::istream &is, Book &item);  // NOLINT
  friend std::ostream &operator<<(std::ostream &os, const Book &item);
  friend std::istream &operator>>(std::istream &is, Book &item);
  friend bool operator==(const Book &lhs, const Book &rhs);
  friend bool operator!=(const Book &lhs, const Book &rhs);

 public:
  operator bool() const {
    return price ? true : false;
  }
  Book() = default;  // default constructor
  Book(const std::string &s) : bookNo(s) {}  // NOLINT
  Book(const std::string &s, unsigned n, double p)
      : bookNo(s), units_sold(n), price(p) {
        revenue = price * units_sold;
      }
  Book(const Book &rhs);  // copy constructor
  Book(Book &&rhs) noexcept;  // move constructor
  Book &operator=(const Book &rhs);  // copy assignment operator
  Book &operator=(Book &&rhs) noexcept;  // move assignment operator
  ~Book() { }  // destroctor (not nessary)
  Book &operator+=(const Book &rhs);

 private:
  std::string bookNo;
  unsigned units_sold = 0;
  double price = 0;
  double revenue = 0;
};
std::istream &read(std::istream &is, Book &item);  // NOLINT
std::istream &operator>>(std::istream &is, Book &item);
std::ostream &operator<<(std::ostream &os, const Book &item);
Book operator+(const Book &lhs, const Book &rhs);
bool operator==(const Book &lhs, const Book &rhs);
bool operator!=(const Book &lhs, const Book &rhs);
#endif  // CH14_OVERLOADED_OPERATIONS_AND_CONVERSIONS_BOOK_14_49_H_
