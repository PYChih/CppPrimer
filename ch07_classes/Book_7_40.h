#ifndef CH07_CLASSES_BOOK_7_40_H_
#define CH07_CLASSES_BOOK_7_40_H_
#include <string>
#include <iostream>
class Book {
  friend std::istream &read(std::istream &is, Book &item);  // NOLINT
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
std::istream &read(std::istream &is, Book &item) {  // NOLINT
  is >> item.bookNo >> item.units_sold >> item.price;
  item.revenue = item.units_sold * item.price;
  return is;
}
#endif  // CH07_CLASSES_BOOK_7_40_H_
