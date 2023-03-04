#include <iostream>

int main() {
    // NULL pointer - they are the same
    void *pVoid = nullptr;
    void *pVoid1 = NULL;
    void *pVoid2 = 0;

    std::cout << pVoid << std::endl;
    std::cout << pVoid1 << std::endl;
    std::cout << pVoid2 << std::endl;

    // pointer to value in memory
    int var = 8;
    int * pVar = &var;  // just pointing to memory address

    double *dVar = (double *) &var;  // type does not matter, types helps to manipulate data, but ultimatly they are complitely meaningless

    std::cout << pVar << std::endl;
    std::cout << dVar << std::endl;


    // dereferencing the pointer,
    *pVar = 10;  // we are writing value to memory address
    std::cout << dVar << std::endl;

    // pointer does not hold data, pointer is just a memory address
    // event if it is a pointer to integer, it is just a pointer to memory address there the integer stored

    // previously data was allocated on stack
    // now we are setting 8 bytes on heap
    char *buffer = new char[8];
    memset(buffer, 0, 8);

    char **ptr = &buffer;  // pointer to pointer


    delete[] buffer; // deleting data
}
