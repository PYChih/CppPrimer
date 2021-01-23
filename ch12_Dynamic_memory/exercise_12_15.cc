// Exercise 12.15:
//  Rewrite the first exercise to use a lambda
//  in place of the end_connection function.
#include <memory>
using std::shared_ptr;
using std::unique_ptr;
#include "exercise_12_15.h"  // NOLINT
void f(destination &d) {  // NOLINT
  connection c = connect(&d);
  // do something
  shared_ptr<connection> c_sptr(&c,
    [](connection* c_ptr) { disconnect(*c_ptr); });
}
void f_unique(destination &d) {  // NOLINT
  connection c = connect(&d);
  // do something
  unique_ptr<connection, decltype(end_connection)*>
  c_uptr(&c, end_connection);
}
int connection::c_inc = 0;
int main() {
    destination d;
    f(d);
    f(d);
    f(d);
    std::cout << "unique ptr !!!" << std::endl;
    f_unique(d);
}



