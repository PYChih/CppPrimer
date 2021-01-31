#ifndef CH13_COPY_CONTROL_EXERCISE_13_47_H_
#define CH13_COPY_CONTROL_EXERCISE_13_47_H_
#include <utility>
#include <memory>
class String {
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
#endif  // CH13_COPY_CONTROL_EXERCISE_13_47_H_
