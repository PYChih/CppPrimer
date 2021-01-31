#ifndef STRVEC_H_
#define STRVEC_H_
#include <string>
#include <memory>
#include <utility>
#include <initializer_list>
using std::string;
using std::allocator;
using std::pair;
using std::initializer_list;
class StrVec {
 public:
  StrVec():
    elements(nullptr), first_free(nullptr), cap(nullptr) { }
  StrVec(const StrVec &sv);  // copy constructor
  StrVec(initializer_list<string> il);  // NOLINT
  StrVec &operator=(const StrVec&);  // copy-assignment operator
  ~StrVec();  // destructor
  StrVec(StrVec &&sv) noexcept;  // move constructor
  StrVec &operator=(StrVec &&rhs) noexcept;  // move-assignment operator
  void push_back(const string&);  // const reference push_back
  size_t size() const { return first_free - elements; }
  size_t capacity() const { return cap - elements; }
  string *begin() const { return elements; }
  string *end() const { return first_free; }
  void reserve(size_t sz);
  void resize(size_t n, const string& s_val = "");

 private:
  static allocator<string> alloc;
  void chk_n_alloc() {
    if (size() == capacity()) { reallocate(); }
  }
  pair<string*, string*> alloc_n_copy(const string*, const string*);  // 2
  void free();  // 3
  void reallocate();
  string *elements;
  string *first_free;
  string *cap;
};
#endif  // STRVEC_H_
