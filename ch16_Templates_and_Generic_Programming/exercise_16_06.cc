// Exercise 16.6:
// How do you think the library begin and end functions that take an array
// argument work?
//  std::begin  is a template function that takes a reference to an array.It
//  returns this reference as the iterator pointing to the first element in
//  this array.
//
//  std::end    is a template function that takes a reference to an array and
//  capture the size.
//  It return this reference plus the size as the iterator pointing
//  to one past last element
//
// Define your own versions of these functions.
#include <iostream>
using std::cout;
using std::endl;
void print(const int *beg, const int *end) {
  while (beg != end) {
    cout << *beg++ << endl;
  }
}
template<typename T, unsigned sz>
T* self_begin(T (&arr)[sz]) {
  return arr;
}
template<typename T, unsigned sz>
T* self_end(T (&arr)[sz]) {
  return arr + sz;
}
int main() {
  int arr[] = {1, 2, 3, 4, 5};
  print(std::begin(arr), std::end(arr));
  print(self_begin(arr), self_end(arr));
}