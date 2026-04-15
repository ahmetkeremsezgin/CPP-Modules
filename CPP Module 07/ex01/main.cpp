#include <iostream>
#include "iter.hpp"

template <typename T>
void printElement(T const & x) {
    std::cout << x << " ";
}

void increment(int & n) {
    n++;
}

int main() {
    int intArray[] = {0, 1, 2, 3, 4};
    size_t intLen = 5;

    std::cout << "Original integer array: ";
    ::iter(intArray, intLen, printElement<int>);
    std::cout << std::endl;

    std::cout << "After increasing the number of employees: ";
    ::iter(intArray, intLen, increment);
    ::iter(intArray, intLen, printElement<int>);
    std::cout << "\n" << std::endl;

    std::string strArray[] = {"C++", "Templates", "Are", "Cool"};
    size_t strLen = 4;

    std::cout << "String dizisi: ";
    ::iter(strArray, strLen, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}