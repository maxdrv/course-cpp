#include <iostream>
#include <string>

/**
 * char is 1 byte
 * it is just ascii symbols
 *
 * we can not fit all languages in this bounds
 * you need extra work to represent russian or chinese symbols for example
 */

void PrintString(const std::string &string) {  // we passing using reference
    std::cout << string << std::endl;
}

int main() {

    const char *name = "Max";  // fixed block of memory (const char array)
    // no need to use delete
//    name[1] = 'i';

    // string ended with null termination pointer, that's how computer know when string ends
    std::cout << name << std::endl;

    char name2[3] = {'M', 'a', 'x'};
    std::cout << name2 << std::endl;  // because we do not have null pointer terminator std does not know when to end

    char name3[4] = {'M', 'a', 'x', '\0'};
    char name4[4] = {'M', 'a', 'x', 0};
    std::cout << name3 << std::endl;


    // use std::string over char arrays
    std::string name5 = "Max5";
    std::cout << name5 << std::endl;
    std::cout << name5.size() << std::endl;


    std::string name6 = "Max6";  //  + "Hi" you can't concatenate const char array
    // how ever if you working with string pointer - you can do it
    name6 += " Hi";

    PrintString("asdf");


}