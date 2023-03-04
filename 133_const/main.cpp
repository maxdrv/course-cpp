#include <iostream>

int main() {
    const int MAX_AGE = 90;  // you can not change this int (but we can)  it is more like a promise to

    int *a = new int;
    *a = 2;
    a = (int *) &MAX_AGE;  // bypass const int  // we broke const promise
    std::cout << *a << std::endl;

    const int *b = new int;
//    int const *b = new int;  // same thing
//    *b = 2;  // you can not change content of that pointer
    b = (int *) &MAX_AGE;  // however you can change there this pointer points


    int * const c = new int;
    *c = 3;  // now we can change value
//    c = (int *) &MAX_AGE;  // but can not reassign


    const int *const d = new int;  // no reassined to content or to pointer

}