#include <iostream>
/**
 * static variable - only one variable for all class/struct instances
 * static methods - can not call instance methods
 */

struct Entity {
    static int x, y;

    int a, b;

    void Print() {
        std::cout << x << " " << y << std::endl;
    }

    void PrintAB() {
        std::cout << a << " " << b << std::endl;
    }
};

// this is what class method essentially is
// they are just functions with extra argument which is entity instance
static void Print(Entity e) {
    std::cout << e.a << " " << e.b << std::endl;
}

int Entity::x;
int Entity::y;

int main() {

    Entity e;
    e.x = 1;
    e.y = 2;

    Entity e2;
    e2.x = 8;
    e2.y = 9;

    // they will print the same value since
    e.Print();
    e2.Print();

    // accessing x/y vie instance is a bad hobbit
    // you should access them vie class
    std::cout << Entity::x << std::endl;
    std::cout << Entity::y << std::endl;

    // it is more like a namespace for variable
    // why we would use this if we can just create a global variable
    // or it could be static global variable
    // we can get the same effect but why then you static class members
    // it make sense to put inside Entity class, for organization purposes for example

    return 0;
}