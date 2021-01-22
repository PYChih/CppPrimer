// Exercise 13_17
// Write versions of numbered and f corresponding to the
// previous three exercises and check whether
// you correctly predicted the output.
// see 14~16

#include <iostream>
#include "exercise_13_18.h"  // NOLINT
int Employee::s_increment = 0;

int main() {
    Employee e1("David"), e2("Bryan");
    std::cout << e1.myid() << std::endl;
    std::cout << e2.myid() << std::endl;
}




