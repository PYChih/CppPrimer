#ifndef CH14_OVERLOADED_OPERATIONS_AND_CONVERSIONS_STRING_14_07_H_
#define CH14_OVERLOADED_OPERATIONS_AND_CONVERSIONS_STRING_14_07_H_
#include <iostream>
#include <utility>
#include <memory>
class String {
  friend std::ostream &operator<<(std::ostream &os, const String &s);

 public:
    String():  // default constructure
      elements(nullptr), first_free(nullptr), cap(nullptr) { }
    String(const char* char_arr);  //NOLINT
    String(const String&);  // copy constructure
    String &operator=(const String& s);  // copy assign operator
    ~String() { free(); }
    void push_back(const char& c);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    char* begin() const { return elements; }
    char* end() const { return first_free; }

 private:
  static std::allocator<char> alloc;
  void chk_n_alloc()
    { if (size() == capacity()) reallocate(); }
  std::pair<char*, char*> alloc_n_copy
      (const char *b, const char *e);
  void free();
  void reallocate();
  char *elements;  // pointer to first element
  char *first_free;  // pointer to first free element
  char *cap;  // off the end
};
std::ostream &operator<<(std::ostream &os, const String &s);
#endif  // CH14_OVERLOADED_OPERATIONS_AND_CONVERSIONS_STRING_14_07_H_
