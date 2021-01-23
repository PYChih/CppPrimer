// Exercise 12.15:
//  Rewrite the first exercise to use a lambda
//  in place of the end_connection function.
#include <memory>
using std::shared_ptr;
#include "exercise_12_15.h"  // NOLINT
void f(destination &d) { // NOLINT
    connection c = connect(&d);
    // do something
    shared_ptr<connection> c_sptr(&c,
     [](connection* c_ptr) { disconnect(*c_ptr); });
}
int connection::c_inc = 0;
int main() {
    destination d;
    f(d);
    f(d);
    f(d);
}



