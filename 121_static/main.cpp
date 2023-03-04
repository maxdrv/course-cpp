#include <iostream>

//int s_variable = 10;  // same name as variable inside Static.cpp

extern int s_variable;  // we will look for s_variable outside this translation unit file

int main() {
    std::cout << s_variable << std::endl;
    return 0;
}