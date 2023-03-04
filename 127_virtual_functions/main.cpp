#include <iostream>

class Entity {
public:
    virtual std::string GetName() {
        return "Entity";
    }
};

class Player : public Entity {
private:
    std::string m_Name;
public:
    Player(const std::string &name)
            : m_Name(name) {

    }

    // override not nessassary but helps discover bugs for example if we misspell function name
    std::string GetName() override {
        return m_Name;
    }
};

// virtual function introduce dynamic dispatch which is implemented by v table
// v_table contains the mapping for all virtual functions inside base class so we can map them to correct overriten functions at runtime
//

int main() {
    Entity *e = new Entity;
    Player *p = new Player("Max");

    std::cout << e->GetName() << std::endl;
    std::cout << p->GetName() << std::endl;

    Entity *entity = p;
    // without virtual: we print Entity, but we expect Player's name cause it is still is Player
    std::cout << entity->GetName() << std::endl;

    // virtual fucntions are not free
    // first we spent memory for vtable
    // also every time we call function we spent time going through this vtable
    // to find which function actually call

}