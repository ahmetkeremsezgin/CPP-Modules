#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
    std::vector<int> v1(1, 5);
    v1.push_back(3);
    v1.push_back(42);

    try {
        std::vector<int>::iterator it = easyfind(v1, 3);
        std::cout << "Found value: " << *it << std::endl;

        int index = std::distance(v1.begin(), it);
        std::cout << "At index: " << index << std::endl;

        easyfind(v1, 99);
    } 
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}