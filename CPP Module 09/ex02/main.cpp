#include "PmergeMe.hpp"
#include <iomanip>

int main(int argc, char **argv) {
    if (argc < 2) return 1;

    PmergeMe::printBefore(argc, argv);
    
    std::vector<int> vec;
    std::deque<int> deq;

    double time_vec = PmergeMe::execute(argc, argv, vec);
    double time_deq = PmergeMe::execute(argc, argv, deq);

    std::cout << "After:  ";
    for (size_t i = 0; i < vec.size(); ++i) {
        if (i < 5) std::cout << vec[i] << " ";
        else if (i == 5 && vec.size() > 6) {
            std::cout << "[...]";
            break;
        }
        else if (i == 5 && vec.size() <= 6) std::cout << vec[i];
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << vec.size() 
              << " elements with std::vector : " << std::fixed << std::setprecision(5) << time_vec << " us" << std::endl;
    
    std::cout << "Time to process a range of " << deq.size() 
              << " elements with std::deque  : " << std::fixed << std::setprecision(5) << time_deq << " us" << std::endl;

    return 0;
}