#include "PmergeMe.hpp"
#include <iomanip>

void check_pars(int argc, char** argv) {
    for (int i = 1; i < argc; ++i) {
        if (argv[i][0] == '\0') {
            std::cerr << "Error" << std::endl;
            std::exit(1);
        }

        for (int j = 0; argv[i][j] != '\0'; ++j) {
            if (argv[i][j] < '0' || argv[i][j] > '9') {
                std::cerr << "Error" << std::endl;
                std::exit(1);
            }
        }
        long val = std::strtol(argv[i], NULL, 10);
        if (val > 2147483647 || val < 0) {
            std::cerr << "Error" << std::endl;
            std::exit(1);
        }
    }
}

int main(int argc, char **argv) {
    
    check_pars(argc, argv);
    PmergeMe::printBefore(argc, argv);
    
    std::vector<int> vec;
    std::deque<int> deq;

    double time_vec = PmergeMe::execute(argc, argv, vec);
    double time_deq = PmergeMe::execute(argc, argv, deq);

    std::cout << "After:  ";
    int limit = (vec.size() > 4) ? 4 : vec.size();
    for (int i = 0; i < limit; ++i) {
        std::cout << vec[i] << (i == limit - 1 ? "" : " ");
    }
    if (vec.size() > 4) std::cout << " [...]";
    std::cout << std::endl;
    
    std::cout << "Time to process a range of " << vec.size() 
              << " elements with std::vector : " << std::fixed << std::setprecision(5) << time_vec << " us" << std::endl;
    
    std::cout << "Time to process a range of " << deq.size() 
              << " elements with std::deque  : " << std::fixed << std::setprecision(5) << time_deq << " us" << std::endl;

    return 0;
}