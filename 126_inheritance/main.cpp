#include <iostream>

class Entity {
public:
    float X, Y;

    void Move(float xa, float ya) {
        X += xa;
        Y += ya;
    }
};

// now player now has everything Entity has
class Player : public Entity {
public:
    const char *Name;

    void PrintName() {
        std::cout << Name << std::endl;
    }
};

int main() {

    Player player;

    player.Move(1.0f, 2.0f);
    player.PrintName();


    std::cout << sizeof(Entity) << std::endl;
    std::cout << sizeof(Player) << std::endl;
}