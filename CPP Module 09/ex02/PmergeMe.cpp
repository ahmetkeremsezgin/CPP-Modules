#include "PmergeMe.hpp"

void PmergeMe::printBefore(int argc, char **argv) {
    std::cout << "Before: ";
    int limit = (argc > 6) ? 5 : argc - 1;
    for (int i = 1; i <= limit; ++i) {
        std::cout << argv[i] << (i == limit ? "" : " ");
    }
    if (argc > 6) std::cout << " [...]";
    std::cout << std::endl;
}