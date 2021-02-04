#ifndef CH14_OVERLOADED_OPERATIONS_AND_CONVERSIONS_STRBLOBPTR_14_32_H_
#define CH14_OVERLOADED_OPERATIONS_AND_CONVERSIONS_STRBLOBPTR_14_32_H_
#include <string>
#include <vector>
#include <initializer_list>
#include <memory>
#include <exception>
class PtrStrBlobPtr;
class StrBlobPtr;
class ConstStrBlobPtr;
class StrBlob {
  friend StrBlobPtr;
  friend ConstStrBlobPtr;
  friend bool operator==(const StrBlob &lhs, const StrBlob &rhs);
  friend bool operator!=(const StrBlob &lhs, const StrBlob &rhs);
  friend bool operator<(const StrBlob &lhs, const StrBlob &rhs);
  friend bool operator>(const StrBlob &lhs, const StrBlob &rhs);

 public:
  typedef std::vector<std::string>::size_type size_type;
  StrBlob();
  StrBlob(std::initializer_list<std::string> il);
  size_type size() const {return data->size();}
  void push_back(const std::string &t) {data->push_back(t);}
  void pop_back();
  std::string &front();
  std::string &back();
  const std::string &front() const;
  const std::string &back() const;
  StrBlobPtr begin();
  StrBlobPtr end();
  ConstStrBlobPtr begin() const;
  ConstStrBlobPtr end() const;
  std::string &operator[](size_type n);
  const std::string &operator[](size_type n) const;

 private:
  std::shared_ptr<std::vector<std::string>> data;
  void check(size_type i, const std::string &msg) const;
};
class StrBlobPtr {
  friend bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
  friend bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
  friend bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
  friend bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
  friend StrBlobPtr operator+(const StrBlobPtr &lhs, std::size_t n);

 public:
  StrBlobPtr() : curr(0) { }
  StrBlobPtr(StrBlob &a, std::size_t sz)  // non-const reference
      : data_wp(a.data), curr(sz) { }
  std::string &deref() const;
  std::string &operator*() const;
  std::string *operator->() const;
  StrBlobPtr &incr();
  std::string &operator[](std::size_t n);
  const std::string &operator[](std::size_t n) const;
  StrBlobPtr operator++(int);  // postfix
  StrBlobPtr &operator++();  // prefix
  StrBlobPtr operator--(int);  // postfix
  StrBlobPtr &operator--();  // prefix
  StrBlobPtr &operator+=(std::size_t n);

 private:
  std::shared_ptr<std::vector<std::string>> check(std::size_t sz,
      const std::string &msg) const;
  std::weak_ptr<std::vector<std::string>> data_wp;
  std::size_t curr;
};
class ConstStrBlobPtr {
  friend bool operator==(const ConstStrBlobPtr &lhs,
                         const ConstStrBlobPtr &rhs);
  friend bool operator!=(const ConstStrBlobPtr &lhs,
                         const ConstStrBlobPtr &rhs);
  friend bool operator<(const ConstStrBlobPtr &lhs,
                        const ConstStrBlobPtr &rhs);
  friend bool operator>(const ConstStrBlobPtr &lhs,
                        const ConstStrBlobPtr &rhs);
  friend ConstStrBlobPtr operator+(const ConstStrBlobPtr &lhs,
                                   std::size_t n);

 public:
  ConstStrBlobPtr() : curr(0) { }
  ConstStrBlobPtr(const StrBlob &a, std::size_t sz)
      : data_wp(a.data), curr(sz) { }
  const std::string &deref() const;
  const std::string &operator*() const;
  const std::string *operator->() const;
  ConstStrBlobPtr &incr();
  std::string &operator[](std::size_t n);
  const std::string &operator[](std::size_t n) const;
  ConstStrBlobPtr operator++(int);  // postfix
  ConstStrBlobPtr &operator++();  // prefix
  ConstStrBlobPtr &operator+=(std::size_t n);
  ConstStrBlobPtr &operator--();  // prefix
  ConstStrBlobPtr operator--(int);  // postfix

 private:
  std::shared_ptr<std::vector<std::string>> check(std::size_t sz,
      const std::string &msg) const;
  std::weak_ptr<std::vector<std::string>> data_wp;
  std::size_t curr;
};
bool operator==(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs);
bool operator!=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs);
bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator==(const StrBlob &lhs, const StrBlob &rhs);
bool operator!=(const StrBlob &lhs, const StrBlob &rhs);
bool operator<(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs);
bool operator>(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs);
bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator<(const StrBlob &lhs, const StrBlob &rhs);
bool operator>(const StrBlob &lhs, const StrBlob &rhs);
ConstStrBlobPtr operator+(const ConstStrBlobPtr &lhs,
                                   std::size_t n);
StrBlobPtr operator+(const StrBlobPtr &lhs, std::size_t n);
class PtrStrBlobPtr {
 public:
  PtrStrBlobPtr() = default;
  PtrStrBlobPtr(StrBlobPtr* p) : psbp(p) { }  // NOLINT
  StrBlobPtr &operator*() const;
  StrBlobPtr *operator->() const;

 private:
  StrBlobPtr *psbp;
};
#endif  // CH14_OVERLOADED_OPERATIONS_AND_CONVERSIONS_STRBLOBPTR_14_32_H_