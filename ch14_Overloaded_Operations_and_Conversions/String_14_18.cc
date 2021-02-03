#include <cstring>
#include "String_14_18.h"  // NOLINT
using std::allocator;
using std::pair;
using std::uninitialized_copy;
using std::cout;
using std::endl;
allocator<char> String::alloc;
void String::push_back(const char &c) {
    chk_n_alloc();
    alloc.construct(first_free++, c);
}
pair<char*, char*>
String::alloc_n_copy(const char *b, const char *e) {
  auto data = alloc.allocate(e - b);
  return {data, uninitialized_copy(b, e, data)};
}
void String::free() {
    if (elements) {
        for (auto p = first_free; p != elements; ) {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);
    }
}
String::String(const String &s) {
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}
String::String(String &&s) noexcept  // move constructor
    : elements(s.elements), first_free(s.first_free), cap(s.cap) {
    cout << "moving~" << endl;
    s.elements = s.first_free = s.cap = nullptr;
}
String &String::operator=(const String &rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}
String& String::operator=(String &&rhs) noexcept {  // move-assignment operator
    cout << "moving~op" << endl;
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}
void String::reallocate() {
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}
String::String(const char* char_arr) {
    // C-style char array constructure
    if (char_arr) {
      auto data = alloc_n_copy(char_arr, char_arr + strlen(char_arr));
      elements = data.first;
      first_free = cap = data.second;
    } else {
      elements = first_free = cap = nullptr;
    }
}
std::ostream &operator<<(std::ostream &os, const String &s) {
  auto beg = s.elements;
  while (beg != s.first_free) {
    os << *beg;
    ++beg;
  }
  return os;
}
std::istream &operator>>(std::istream &is, String &s) {
  for (char c; (c = is.get()) != '\n';) {
    s.push_back(c);
  }
  return is;
}
bool operator==(const String &lhs, const String &rhs) {
  return (lhs.size() == rhs.size() &&
          std::equal(lhs.begin(), lhs.end(), rhs.begin()));
}
bool operator!=(const String &lhs, const String &rhs) {
  return !(lhs == rhs);
}