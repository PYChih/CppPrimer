#ifndef CH16_TEMPLATES_AND_GENERIC_PROGRAMMING_SCREEN_16_14_H_
#define CH16_TEMPLATES_AND_GENERIC_PROGRAMMING_SCREEN_16_14_H_
#include <string>
#include <iostream>
template<unsigned H, unsigned W>
class Screen;
template <unsigned H, unsigned W>
std::ostream &operator<<(std::ostream &os, const Screen<H, W> &c);
template <unsigned H, unsigned W>
std::istream &operator>>(std::istream &is, Screen<H, W> &c);
template<unsigned H, unsigned W>
class Screen {
 public:
  typedef std::string::size_type pos;
  Screen() = default;
  Screen(char c) : contents(H * W, c) { }  // NOLINT
  Screen &set(pos, pos, char);
  Screen &set(char);
  char get() const {
    return contents[cursor];
  }
  Screen &move(pos r, pos c);
  friend std::ostream &operator<<<H, W>(std::ostream &os, const Screen<H, W> &c);
  friend std::istream &operator>><H, W>(std::istream &is, Screen<H, W> &c);
 private:
  pos cursor = 0;
  pos height = H;
  pos width = W;
  std::string contents;
};
template<unsigned H, unsigned W>
inline Screen<H, W> &Screen<H, W>::move(pos r, pos c) {  // NOLINT
  pos row = r * width;
  cursor = row + c;
  return *this;
}
template<unsigned H, unsigned W>
inline Screen<H, W> &Screen<H, W>::set(char ch) {
  contents[cursor] = ch;
  return *this;
}
template<unsigned H, unsigned W>
inline Screen<H, W> &Screen<H, W>::set(pos row, pos col, char ch) {
  contents[row * W + col] = ch;
  return *this;
}
template <unsigned H, unsigned W>
std::ostream &operator<<(std::ostream &os, const Screen<H, W> &c) {
  unsigned int i;
  for ( i = 0; i < c.height; ++i ) {
    os << c.contents.substr(i*W, W) << std::endl;
  }
  return os;
}
template <unsigned H, unsigned W>
std::istream &operator>>(std::istream &is, Screen<H, W> &c) {
  char a;
  is >> a;
  std::string temp(H * W, a);
  c.contents = temp;
  return is;
}
#endif  // CH16_TEMPLATES_AND_GENERIC_PROGRAMMING_SCREEN_16_14_H_