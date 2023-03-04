#include <iostream>

class Entity {
private:
    int m_X;
    int *m_Y;
public:

    int GetX() const {  // this method is not going modify class variables  (read only method)
        return m_X;
    }

    // returning pointer that can not be modified
    // content of pointer is not modified
    // class variables not modified
    const int* const GetY() const {
        return m_Y;
    }

};

void PrintEntity(const Entity& entity) {
    std::cout << entity.GetY() << std::endl;
}

int main() {

}