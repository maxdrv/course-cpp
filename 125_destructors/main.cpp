#include <iostream>

/**
 * if you have stack based entity - destructor will be called on escaping outside of the scope of the stack
 *
 * if you have heap entity - destructor called delete
 *
 * if you initialize something in constructor
 * you want to destroy them in desctructor becase you do not want memory leaks
 * heap allocated objects manually -> you need delete them manually
 *
 * you can call destructor but not something you need to do
 *
 */
class Entity {
    float x_, y_;

public:
    Entity() {
        x_ = 0.0f, y_ = 0.0f;
    }

    ~Entity() {
        std::cout << "Object has been deleted!" << std::endl;
    }

};

int main() {
    Entity e;


    return 0;
}