#include <iostream>

class Entity {
public:
    float x, y;

    void Print() {
        std::cout << x << ", " << y << std::endl;
    }
};

class Entity2 {
public:
    float x_, y_;

    Entity2() {
        x_ = 0.0f, y_ = 0.0f;
    }

    Entity2(float x, float y) {
        x_ = x;
        y_ = y;
    }

    void Print() {
        std::cout << x_ << ", " << y_ << std::endl;
    }

};

class Entity3 {
    Entity3() = delete;  // you can remove default constructor if you want

    // or you can make it private
};

int main() {
    Entity e1;
    std::cout << e1.x << std::endl;
    e1.Print();  // we got simingle random values; we got whatever was in memory

    Entity2 e2;
    e2.Print();  // now we variable initialized with zeroes

    Entity2 e22(2.4f, 4.6f);
    e22.Print();

    return 0;
}