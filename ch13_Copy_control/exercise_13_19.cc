// Exercise 13_17
// Write versions of numbered and f corresponding to the
// previous three exercises and check whether
// you correctly predicted the output.
// see 14~16

#include <iostream>
#include "exercise_13_19.h"  // NOLINT
int Employee::s_increment = 0;

int main() {
    Employee e1("David"), e2 = e1, e3;
    e3 = e1;
    std::cout << e1.myid() << std::endl;
    std::cout << e2.myid() << std::endl;
    std::cout << e3.myid() << std::endl;
}




