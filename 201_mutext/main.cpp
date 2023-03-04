#include <mutex>
#include <iostream>

int main() {

    std::mutex m;

    m.lock();
    std::cout << "locked 1" << std::endl;

    // C++ mutex is not reentrant
    m.lock();
    std::cout << "locked 2" << std::endl;

    m.unlock();
}