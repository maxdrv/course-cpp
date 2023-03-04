#include <iostream>

// c++ does not have interface key word
class Printable {
public:
    virtual std::string GetClassName() = 0;
};

class Entity : public Printable {
public:
    virtual std::string getName() = 0;  // zero means we did not provide any implementation

    std::string GetClassName() override {
        return "Entity";
    }
};

class Player : public Entity {
public:
    std::string getName() {
        return "PlayerName";
    }

    std::string GetClassName() override {
        return "Player";
    }


};

void Print(Printable * obj) {
    std::cout << obj->GetClassName() << std::endl;
}

int main() {
//    Entity entity;  // we can not init intance of this class after we make it pure virtual

    Player player;

    Print(&player);
}