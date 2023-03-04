#include <iostream>

int main() {
    int variableInt = 8;  // 4 bytes
    std::cout << variableInt << std::endl;
    unsigned variableIntUnsigned = 1000;

    // all of them can be unsigned
    char varChar;
    short varShort;
    int varInt;
    long varLong;
    long long varLongLong;  // may depend on platform

    // decimal
    float varFloat = 5.5f;  // 4 bytes (appending f defines float, absence - double)
    double varDouble = 5.5;  // 8 bytes

    bool varBool = true;  // or false; 1 byte
    bool varBool0 = 0;  // zero is false
    bool varBool1 = 1;  // anything not zero is true
    std::cout << varBool0 << " " << varBool1 << std::endl;

    std::cout << sizeof(varBool) << std::endl;


    return 0;
}