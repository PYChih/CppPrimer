// Exercise 16.19:
// Write a function that takes a reference to a container and prints the
// elements in that container. Use the container’s size_type and size members
// to control the loop that prints the elements.
#include <iostream>
#include <vector>
#include <list>
template <typename Container>
std::ostream &print(Container const &container, std::ostream &os) {
  for (typename Container::size_type i = 0; i != container.size(); ++i) {
    os << container[i] << " ";
  }
  return os;
}
int main() {
  std::vector<int> v = {1, 2, 3, 4, 5};
  print(v, std::cout) << std::endl;
}