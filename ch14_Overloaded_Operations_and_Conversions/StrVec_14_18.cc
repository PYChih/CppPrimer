#include "StrVec_14_18.h"  // NOLINT
using std::make_pair;
allocator<string> StrVec::alloc;
void StrVec::push_back(const string& s) {
  chk_n_alloc();
  alloc.construct(first_free++, s);
}
pair<string*, string*> StrVec::alloc_n_copy(
    const string *s_beg, const string *s_end) {
  string* new_elements = alloc.allocate(size());
  string* new_first_free = uninitialized_copy(s_beg, s_end, new_elements);
  return make_pair(new_elements, new_first_free);
}
void StrVec::free() {
  if (!elements) {
    while (first_free != elements) {
      alloc.destroy(--first_free);
    }
    alloc.deallocate(elements, cap-elements);
  }
}
StrVec::StrVec(const StrVec &sv) {  // copy constructure
  pair<string*, string*> new_data = alloc_n_copy(sv.begin(), sv.end());
  elements = new_data.first;
  first_free = new_data.second;
  cap = new_data.second;
}
// move constructure
StrVec::StrVec(StrVec &&sv) noexcept:
  elements(sv.elements), first_free(sv.first_free), cap(sv.cap) {
  sv.elements = sv.first_free = sv.cap = nullptr;
}
// move assignment operator
StrVec &StrVec::operator=(StrVec &&rhs) noexcept {
  if (this != &rhs) {
      free();
      elements = rhs.elements;
      first_free = rhs.first_free;
      cap = rhs.cap;
      rhs.elements = rhs.first_free = rhs.cap = nullptr;
  }
  return *this;
}
StrVec::~StrVec() {
  free();
}
StrVec& StrVec::operator=(const StrVec& sv) {
  pair<string*, string*> new_data = alloc_n_copy(sv.begin(), sv.end());
  free();
  elements = new_data.first;
  first_free = new_data.second;
  cap = new_data.second;
  return *this;
}
void StrVec::reallocate() {
  size_t new_capacity = size() ? size() * 2 : 1;
  string* new_element = alloc.allocate(new_capacity);
  string* new_first_free = new_element;
  string* old_element = elements;
  for (size_t i = 0; i != size(); ++i) {
    alloc.construct(new_first_free++, std::move(*old_element++));
  }
  free();
  elements = new_element;
  first_free = new_first_free;
  cap = new_element + new_capacity;
}
void StrVec::reserve(size_t sz) {
  if (capacity() < sz) {
    size_t new_capacity = sz;
    string* new_element = alloc.allocate(new_capacity);
    string* new_first_free = new_element;
    string* old_element = elements;
    for (size_t i = 0; i != size(); ++i) {
      alloc.construct(new_first_free++, std::move(*old_element++));
    }
    free();
    elements = new_element;
    first_free = new_first_free;
    cap = new_element + new_capacity;
  }
}
void StrVec::resize(size_t n, const string &s_val) {
  size_t new_capacity = n;
  string* new_element = alloc.allocate(n);
  string* new_first_free = new_element;
  string* old_element = elements;
  int inc = 0;
  while ((inc < new_capacity) && (inc < size())) {
    alloc.construct(new_first_free++, std::move(*old_element++));
    ++inc;
  }
  if (inc < new_capacity) {
    alloc.construct(new_first_free++, s_val);
    ++inc;
  }
  free();
  elements = new_element;
  first_free = new_first_free;
  cap = new_element + new_capacity;
}
StrVec::StrVec(initializer_list<string> il) {
  size_t new_capacity = il.size();
  string* new_element = alloc.allocate(new_capacity);
  string* new_first_free = new_element;
  for (auto beg = il.begin(); beg != il.end(); ++beg) {
    alloc.construct(new_first_free++, *beg);
  }
  elements = new_element;
  first_free = new_first_free;
  cap = new_element + new_capacity;
}
bool operator==(const StrVec &lhs, const StrVec &rhs) {
  return (lhs.size() == rhs.size() &&
          std::equal(lhs.begin(), lhs.end(), rhs.begin()));
}
bool operator!=(const StrVec &lhs, const StrVec &rhs) {
  return !(lhs == rhs);
}