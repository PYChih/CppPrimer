// Exercise 13.27
// Define your own reference-counted version of HasPtr.
#include <iostream>
#include "exercise_13_27.h"  // NOLINT
int main() {
    HasPtr hp("ptr_like_class");
    std::cout << hp.print_count() << std::endl;
    HasPtr hp2 = hp;
    std::cout << hp.print_count() << std::endl;
    std::cout << hp2.print_count() << std::endl;
    HasPtr hp3;
    std::cout << hp3.print_count() << std::endl;
    hp3 = hp2;
    std::cout << hp3.print_count() << std::endl;
    std::cout << hp2.print_count() << std::endl;
    return 0;
}
