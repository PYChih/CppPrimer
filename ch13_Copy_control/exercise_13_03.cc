// Exercise 13.03
// What happens when we copy a StrBlob?
// What about StrBlobPtrs?
#include <iostream>
#include "exercise_13_03.h"  // NOLINT

int main() {
    StrBlob b1;
    {
        StrBlob b2 = {"a", "an", "the"};
        b1 = b2;
        std::cout << "copy here" << std::endl;
        std::cout << "shared_ptr count : " << b1.count() << std::endl;
        b2.push_back("about");
    }
    std::cout << b1.front() << " " << b1.back() << std::endl;
    std::cout << "shared_ptr count end block : " << b1.count() << std::endl;
    // std::cout << b2.front() << " " << b2.back() << std::endl;
    return 0;
}
