// Exercise 13.47
//  賦予你在13.5練習13.44的String類別中的拷貝建構器和拷貝指定運算子一個述句，在每次該函式執行時，印出一則訊息。
#include <memory>
#include <cstring>
#include <iostream>
#include "exercise_13_47.h"  // NOLINT
using std::cout;
using std::endl;
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
    cout << "I'm copy constructure " << endl;
}
String &String::operator=(const String &rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    cout << "I'm copy assign operator " << endl;
    return *this;
}
void String::reallocate() {
    cout << "reallocating ... " << endl;
    cout << "from " << size() << " to ";
    auto newcapacity = size() ? 2 * size() : 1;
    cout << newcapacity << endl;
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
