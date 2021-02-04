#ifndef CH14_OVERLOADED_OPERATIONS_AND_CONVERSIONS_STRVEC_14_26_H_
#define CH14_OVERLOADED_OPERATIONS_AND_CONVERSIONS_STRVEC_14_26_H_
#include <string>
#include <memory>
#include <utility>
#include <initializer_list>
class StrVec {
  friend bool operator==(const StrVec &lhs, const StrVec &rhs);
  friend bool operator!=(const StrVec &lhs, const StrVec &rhs);
  friend bool operator<(const StrVec &lhs, const StrVec &rhs);
  friend bool operator>(const StrVec &lhs, const StrVec &rhs);

 public:
  StrVec():
    elements(nullptr), first_free(nullptr), cap(nullptr) { }
  StrVec(const StrVec &sv);  // copy constructor
  StrVec(std::initializer_list<std::string> il);  // NOLINT
  StrVec &operator=(const StrVec &sv);  // copy-assignment operator
  ~StrVec();  // destructor
  StrVec(StrVec &&sv) noexcept;  // move constructor
  StrVec &operator=(StrVec &&rhs) noexcept;  // move-assignment operator
  StrVec &operator=(std::initializer_list<std::string> il);
  std::string &operator[](std::size_t n);
  const std::string &operator[](std::size_t n) const;
  void push_back(const std::string &s);  // const reference push_back
  std::size_t size() const { return first_free - elements; }
  std::size_t capacity() const { return cap - elements; }
  std::string *begin() const { return elements; }
  std::string *end() const { return first_free; }
  void reserve(std::size_t sz);
  void resize(std::size_t n, const std::string& s_val = "");

 private:
  static std::allocator<std::string> alloc;
  void chk_n_alloc() {
    if (size() == capacity()) { reallocate(); }
  }
  std::pair<std::string*, std::string*> alloc_n_copy(const std::string*,
      const std::string*);
  void free();  // 3
  void reallocate();
  std::string *elements;
  std::string *first_free;
  std::string *cap;
};
bool operator==(const StrVec &lhs, const StrVec &rhs);
bool operator!=(const StrVec &lhs, const StrVec &rhs);
bool operator<(const StrVec &lhs, const StrVec &rhs);
bool operator>(const StrVec &lhs, const StrVec &rhs);
#endif  // CH14_OVERLOADED_OPERATIONS_AND_CONVERSIONS_STRVEC_14_26_H_
