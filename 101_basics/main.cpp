#include <iostream>

/**
 * source files -> executable or library
 *
 * 1. everything started with # is a preprocessor statement
 * 2. include - just includes everything in presented header file
 * 3. << is just an overloaded operator (basically just a function)
 *  think of std::cout << "hello" as std::cout.print("hello");
 *
 * 4. main is a special case, it does not need to have an return
 * 5. after preprocessing source files are compiled
 * 6. every cpp files compiled to object file (.obj) individually
 * 7. linker takes all .obj files and glues them together into single file
 *
 * 8. I'm only specified function declaration not it's code
 *  Will compiler work with such definition? Yes
 *  How does the compiler know if we have function in another file? It doesn't. It trust us
 *  Why it is working? Linker finds the definition of log function
 *  If it can not find definition? We will get linker error:
 *  Undefined symbols for architecture x86_64:
 *  "log(char const*)", referenced from:
 *     _main in main-9e4c1d.o
 * ld: symbol(s) not found for architecture x86_64
 *
 * 9. Linker function is to wire body to functions, it has to be somewhere
 *
 */

void log(const char *message);

int main() {
    log("Hello, World!");
    return 0;
}
