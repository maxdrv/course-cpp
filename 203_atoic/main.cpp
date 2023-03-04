#include <algorithm>
#include <atomic>
#include <cstddef>
#include <iostream>
#include <thread>
#include <vector>

int main(){
    std::atomic<int> atom{1} ;

    const int current = atom.exchange(1);

    std::cout << current << std::endl;


}