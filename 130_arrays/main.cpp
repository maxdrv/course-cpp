#include <iostream>
#include <array>

class Entity {
public:
    // this memory inlined with object on the heap
    int example[5];

    static const int size = 6;  // it has to be constant
    int example2[size];  // because you should use compile time known variable here

    Entity() {
        for (int i = 0; i < 5; ++i) {
            example[i] = 2;
        }
    }
};

class Entity2 {
public:
    // this memory in different place in heap
    // you can jump there by using address of example2 variable
    // 00 51 ed 02   00 60 00 00 ---[you need to reverse because of endianness]---> 0x0000600002ed5100
    int *example;

    Entity2() {
        example = new int[5];
        for (int i = 0; i < 5; ++i) {
            example[i] = 3;
        }
    }
};

int main() {
    int example[5];
    example[0] = 2;
    example[4] = 4;

    std::cout << example[0] << std::endl;
    std::cout << example << std::endl;  // prints just a memory address

    example[-1];  // memory access violation
    example[5];   // in debug mode error might be thrown, but in release mode you change some variable in your code without realising it

    // usually using less than comparison over less or equal comparison for performance
    // also easier to read because length of arrays is 5 and 5 is comparison
    for (int i = 0; i < 5; ++i) {
        example[i] = 2;
    }

    int *ptr = example;  // arrays are just a pointers
    ptr[3] = 5;  // square brackets just allows us to write with offset to pointer
    // last block can be rewritten
    *(ptr + 3) = 6;  // we adding 3 (using pointer arithmetic) and dereferencing result and write value there
    // number of bytes added to the pointer dependes of data type of the pointer
    // for example if we change data type to char which is 1 byte (over int which is 4 bytes) we have to add X4 amount of data lengths
    *(int *) ((char *) ptr + 12) = 7;


    // arrays on the heap
    int *another = new int[5];  // is not destroyed on the end of the frame
    delete[] another;

    Entity entity;

    Entity2 entity2;

    std::cout << example[3] << std::endl;

    // heap arrays does not have explicit sizes
//    example.size  // or something else
    // of cause there are some ways because the compiler have to know how much memory you have to free when you are deleting array
    // ways dependent on compiler -> you should never trust them
    // sometimes it can be -1 index of array

    // stack arrays
    int a[5];
    sizeof(a); // returns 20  ==> 5 * sizeof(int) = 20 bytes
    int count = sizeof(a) / sizeof(int);  // returns number of elements 20 / 4 = 5

    int *b = new int[5];
    sizeof(b);  // returns 4 ===> size of integer pointer

    std::array<int, 5> arr = {1, 2, 3, 4, 5};  // arrays from c++ 11 std
    arr.size();  // they has size, but as always it is uses more resources than usual array

    std::cout << "end" << std::endl;

}
