#include <iostream>

int add(int a, int b) {
    return a + b;
}

void addAndLog(int a, int b) {
    int res = add(a, b);
    std::cout << res << std::endl;
}

int main() {
    addAndLog(1, 1);
    addAndLog(10, 101);
}