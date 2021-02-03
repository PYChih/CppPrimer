#ifndef CH12_DYNAMIC_MEMORY_STRBLOBPTR_12_19_H_
#define CH12_DYNAMIC_MEMORY_STRBLOBPTR_12_19_H_
#include <string>
#include <vector>
#include <initializer_list>
#include <memory>
#include <exception>
class StrBlobPtr;
class StrBlob {
  friend StrBlobPtr;

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

 private:
  std::shared_ptr<std::vector<std::string>> data;
  void check(size_type i, const std::string &msg) const;
};
class StrBlobPtr {
 public:
  StrBlobPtr() : curr(0) {}
  StrBlobPtr(StrBlob &a, std::size_t sz)  // non-const reference
      : data_wp(a.data), curr(sz) {}
  std::string &deref() const;
  StrBlobPtr &incr();

 private:
  std::shared_ptr<std::vector<std::string>> check(std::size_t sz,
      const std::string &msg) const;
  std::weak_ptr<std::vector<std::string>> data_wp;
  std::size_t curr;
};
#endif  // CH12_DYNAMIC_MEMORY_STRBLOBPTR_12_19_H_