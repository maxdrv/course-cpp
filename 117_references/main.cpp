#include <iostream>

// references is a way to referencing existing variable
// they are not occupie memory

// in most cases reference is just a pointer with syntactic sugar
// you can do everything with pointer what you can do with references
// references are just a sugar to pointers

// copy value to the stack and increment copy, not the initial value
void IncrementWrong(int value) {
    value++;
}

// incrementing memory address
void IncrementWrong2(int* value) {
    *value++;
}

// dereferencing first and increment after
void IncrementRight(int *value) {
    (*value)++;
}

// no need to dereference, if you passing by reference
void IncrementRight2(int &value) {
    value++;
}

int main() {

    int a = 5;
    int &ref = a;  // & part of a type here, it is a reference
    // essentially it is an alias

    ref = 2;

    std::cout << ref << std::endl;
}