#ifndef CH14_OVERLOADED_OPERATIONS_AND_CONVERSIONS_STRBLOBPTR_14_18_H_
#define CH14_OVERLOADED_OPERATIONS_AND_CONVERSIONS_STRBLOBPTR_14_18_H_
#include <string>
#include <vector>
#include <initializer_list>
#include <memory>
#include <exception>
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

 private:
  std::shared_ptr<std::vector<std::string>> data;
  void check(size_type i, const std::string &msg) const;
};
class StrBlobPtr {
  friend bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
  friend bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
  friend bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
  friend bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
 public:
  StrBlobPtr() : curr(0) { }
  StrBlobPtr(StrBlob &a, std::size_t sz)  // non-const reference
      : data_wp(a.data), curr(sz) { }
  std::string &deref() const;
  StrBlobPtr &incr();

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
 public:
  ConstStrBlobPtr() : curr(0) { }
  ConstStrBlobPtr(const StrBlob &a, std::size_t sz)
      : data_wp(a.data), curr(sz) { }
  std::string &deref() const;
  ConstStrBlobPtr &incr();

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
#endif  // CH14_OVERLOADED_OPERATIONS_AND_CONVERSIONS_STRBLOBPTR_14_18_H_