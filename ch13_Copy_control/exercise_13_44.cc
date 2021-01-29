// Exercise 13.44
//  Write a class named String that is
//  a simplified version of the library string class.
//  Your class should have at least a default constructor
//  and a constructor that takes a pointer to a C-style string.
//  Use an allocator to allocate memory that your String class uses.
#include <memory>
#include <cstring>
#include "exercise_13_44.h"  // NOLINT
using std::allocator;
using std::pair;
using std::uninitialized_copy;
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
String &String::operator=(const String &rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
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
