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
    int limit = (argc > 5) ? 4 : argc - 1;
    for (int i = 1; i <= limit; ++i) {
        std::cout << argv[i] << (i == limit ? "" : " ");
    }
    if (argc > 5) std::cout << " [...]";
    std::cout << std::endl;
}

double PmergeMe::runInternalSort(std::vector<int>& raw, std::deque<int>& target, std::clock_t start) {
        std::deque<Node> internal_deq;
        for (size_t i = 0; i < raw.size(); ++i) internal_deq.push_back(Node(raw[i]));
        sortImplementation(internal_deq);
        target.clear();
        for (size_t i = 0; i < internal_deq.size(); ++i) target.push_back(internal_deq[i].value);
        std::clock_t end = std::clock();
        return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
}

double PmergeMe::runInternalSort(std::vector<int>& raw, std::vector<int>& target, std::clock_t start) {
        std::vector<Node> internal_vec;
        for (size_t i = 0; i < raw.size(); ++i) internal_vec.push_back(Node(raw[i]));
        sortImplementation(internal_vec);
        target.clear();
        for (size_t i = 0; i < internal_vec.size(); ++i) target.push_back(internal_vec[i].value);
        std::clock_t end = std::clock();
        return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
}