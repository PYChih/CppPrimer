// Exercise 12.14:
//  Write your own version of a function that
//  uses a shared_ptr to manage a connection.
#include <memory>
using std::shared_ptr;
#include "exercise_12_14.h"  // NOLINT
void f(destination &d) { // NOLINT
    connection c = connect(&d);
    // do something
    shared_ptr<connection> c_sptr(&c, end_connection);
}
int connection::c_inc = 0;
int main() {
    destination d;
    f(d);
    f(d);
    f(d);
}
