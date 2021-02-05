#ifndef CH14_OVERLOADED_OPERATIONS_AND_CONVERSIONS_EXERCISE_14_36_H_
#define CH14_OVERLOADED_OPERATIONS_AND_CONVERSIONS_EXERCISE_14_36_H_
#include <iostream>
#include <string>
class ReadString {
 public:
  ReadString(std::istream &i = std::cin, char c = ' ')  // NOLINT
      : is(i), sep(c) { }
  std::string operator()() {
    std::string ins;
    if (getline(is, ins)) {
      ins += sep;
    }
    return ins;
  }
 private:
  std::istream &is;
  char sep;
};
#endif  // CH14_OVERLOADED_OPERATIONS_AND_CONVERSIONS_EXERCISE_14_36_H_