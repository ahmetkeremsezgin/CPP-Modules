#include "PmergeMe.hpp"

std::vector<size_t> PmergeMe::generateJacobsthal(size_t n) {
    std::vector<size_t> jacob;
    if (n == 0) return jacob;
    jacob.push_back(1);
    if (n == 1) return jacob;
    jacob.push_back(3);
    
    while (true) {
        size_t next = jacob.back() + 2 * jacob[jacob.size() - 2];
        if (next >= n) break;
        jacob.push_back(next);
    }
    return jacob;
}

void PmergeMe::printBefore(int argc, char **argv) {
    std::cout << "Before: ";
    int limit = (argc > 6) ? 5 : argc - 1;
    for (int i = 1; i <= limit; ++i) {
        std::cout << argv[i] << (i == limit ? "" : " ");
    }
    if (argc > 6) std::cout << " [...]";
    std::cout << std::endl;
}