// Exercise 16.12:
// Write your own version of the Blob and BlobPtr templates. including the
// various const members that were not shown in the text.
#include <string>
#include <iostream>
#include "Blob_16_12.h"
#include "BlobPtr_16_12.h"
using std::string;
using std::cout;
using std::endl;
int main() {
  Blob<string> sb = {"a", "b", "c"};
  Blob<int> ib = {1, 2, 3, 4, 5};
  cout << ib.back() << endl;
  cout << sb.back() << endl;
  ib.pop_back();
  sb.pop_back();
  cout << ib.back() << endl;
  cout << sb.back() << endl;
}