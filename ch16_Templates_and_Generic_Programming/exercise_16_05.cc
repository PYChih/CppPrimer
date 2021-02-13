// Exercise 16.5:
// Write a template version of the print function from § 6.2.4 (p. 217) that
// takes a reference to an array and can handle arrays of any size and any
// element type.
#include <iostream>
using std::cout;
using std::endl;
template<unsigned sz>
void print(int (&arr)[sz]) {
  for (auto elem : arr)
    cout << elem << endl;
}
int main() {
  int iarr[] = {1, 2, 4, 5};
  print(iarr);
}