#include <cstddef>
class SmallInt {
  friend
  SmallInt operator+(const SmallInt&, const SmallInt&);
 public:
  SmallInt(int = 0);  // NOLINT
  operator int() const { return val; }  // SmallInt to int
 private:
  std::size_t val;
};
SmallInt s1;
// double d = s1 + 3.14;  // more than one operator + matches
double d = static_cast<int>(s1) + 14;