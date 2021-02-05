#ifndef CH14_OVERLOADED_OPERATIONS_AND_CONVERSIONS_EXERCISE_14_35_H_
#define CH14_OVERLOADED_OPERATIONS_AND_CONVERSIONS_EXERCISE_14_35_H_
#include <iostream>
#include <string>
class ReadString {
 public:
  ReadString(std::istream &i = std::cin, char c = ' ')  // NOLINT
      : is(i), sep(c) { }
  std::string operator()() {
    std::string ins;
    if (is) {
      is >> ins;
    }
    return ins + sep;
  }
 private:
  std::istream &is;
  char sep;
};
#endif  // CH14_OVERLOADED_OPERATIONS_AND_CONVERSIONS_EXERCISE_14_35_H_