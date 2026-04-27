#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "---" << std::endl;

    try {
        Span sp2 = Span(15000);
        std::srand(std::time(NULL));
        for (int i = 0; i < 15000; i++) {
            sp2.addNumber(std::rand());
        }
        std::cout << "15.000 numbers test:" << std::endl;
        std::cout << "Shortest: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest: " << sp2.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "---" << std::endl;

    try {
        Span sp3 = Span(2);
        sp3.addNumber(1);
        sp3.addNumber(10);
        sp3.addNumber(20);
    } catch (const std::exception& e) {
        std::cout << "Expected Exception (Full): " << e.what() << std::endl;
    }

    try {
        Span sp4 = Span(1);
        sp4.addNumber(42);
        sp4.shortestSpan();
    } catch (const std::exception& e) {
        std::cout << "Expected Exception (Too small): " << e.what() << std::endl;
    }

    return 0;
}