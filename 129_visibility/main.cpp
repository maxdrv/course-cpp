
// by default members are private
class Entity {
    int X, Y;

    // also you can use private key word
private:
    int Z;

protected:
    int A;

public:
    Entity() {
        X = 0, Y = 0;
    }
};

class Player : Entity {

public:
    Player() {
        A = 100;  // we can access protected members
    }
};

int main() {

    Entity entity;

//    entity.X;  // you can't access private members, also methods
    // C++ has notion of friend classes, friend class can access private members



}