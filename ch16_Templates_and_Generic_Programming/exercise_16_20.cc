// Exercise 16.20:
// Rewrite the function from the previous exercise to use iterators returned
// from begin and end to control the loop.
#include <iostream>
#include <vector>
#include <list>
template <typename Container>
std::ostream &print(Container const &container, std::ostream &os) {
  // for (typename Container::size_type i = 0; i != container.size(); ++i) {
  //   os << container[i] << " ";
  // }
  for (typename Container::const_iterator beg = container.cbegin();
                                   beg != container.cend(); ++beg) {
    os << *beg << " ";
  }
  return os;
}
int main() {
  std::vector<int> v = {1, 2, 3, 4, 5};
  print(v, std::cout) << std::endl;
}