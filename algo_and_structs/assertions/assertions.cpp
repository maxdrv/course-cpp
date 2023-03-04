#include <iostream>

#include "assertions.h"

void assertTrue(bool actual) {
    if (!actual) {
        std::cout << "ERROR actual value is " << actual << std::endl;
    } else {
        std::cout << "OK" << std::endl;
    }
}
void assertFalse(bool actual) {
    if (actual) {
        std::cout << "ERROR actual value is " << actual << std::endl;
    } else {
        std::cout << "OK" << std::endl;
    }
}