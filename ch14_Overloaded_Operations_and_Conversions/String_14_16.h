#ifndef CH14_OVERLOADED_OPERATIONS_AND_CONVERSIONS_STRING_14_16_H_
#define CH14_OVERLOADED_OPERATIONS_AND_CONVERSIONS_STRING_14_16_H_
#include <iostream>
#include <utility>
#include <memory>
class String {
  friend std::ostream &operator<<(std::ostream &os, const String &s);
  friend std::istream &operator>>(std::istream &is, const String &s);
  friend bool operator==(const String &lhs, const String &rhs);
  friend bool operator!=(const String &lhs, const String &rhs);

 public:
    String():  // default constructure
      elements(nullptr), first_free(nullptr), cap(nullptr) { }
    String(const char* char_arr);  //NOLINT
    String(const String&);  // copy constructure
    String &operator=(const String& s);  // copy assign operator
    String(String &&s) noexcept;  // move constructor
    String &operator=(String &&rhs) noexcept;  // move-assignment operator
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
std::istream &operator>>(std::istream &is, String &s);
bool operator==(const String &lhs, const String &rhs);
bool operator!=(const String &lhs, const String &rhs);

#endif  // CH14_OVERLOADED_OPERATIONS_AND_CONVERSIONS_STRING_14_16_H_