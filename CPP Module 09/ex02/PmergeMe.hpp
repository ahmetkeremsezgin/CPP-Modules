#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cstdlib>
#include <ctime>

class PmergeMe {
private:
    static std::vector<int> generateJacobsthal(int n) {
        std::vector<int> jacob;
        if (n <= 0) return jacob;
        jacob.push_back(3);
        while (true) {
            int next = jacob.back() + 2 * (jacob.size() < 2 ? 1 : jacob[jacob.size() - 2]);
            if (next > n) break;
            jacob.push_back(next);
        }
        return jacob;
    }

    template <typename T>
    static void parseInput(int argc, char** argv, T& container) {
        for (int i = 1; i < argc; ++i) {
            char* endptr;
            long val = std::strtol(argv[i], &endptr, 10);
            if (*endptr != '\0' || val < 0) {
                std::cerr << "Error" << std::endl;
                std::exit(1);
            }
            container.push_back(static_cast<int>(val));
        }
    }

    template <typename T>
    static void sort(T& container) {
        if (container.size() <= 1) return;

        typename T::value_type straggler;
        bool hasStraggler = false;
        if (container.size() % 2 != 0) {
            straggler = container.back();
            hasStraggler = true;
            container.pop_back();
        }

        T winners;
        std::vector<std::pair<typename T::value_type, typename T::value_type> > pairs;

        for (size_t i = 0; i < container.size(); i += 2) {
            typename T::value_type first = container[i];
            typename T::value_type second = container[i + 1];
            if (first < second) std::swap(first, second);
            winners.push_back(first);
            pairs.push_back(std::make_pair(first, second));
        }

        sort(winners);

        T main_chain;
        T pend;
        for (size_t i = 0; i < winners.size(); ++i) {
            main_chain.push_back(winners[i]);
            for (size_t j = 0; j < pairs.size(); ++j) {
                if (pairs[j].first == winners[i]) {
                    pend.push_back(pairs[j].second);
                    break;
                }
            }
        }

        if (!pend.empty())
            main_chain.insert(main_chain.begin(), pend[0]);
        
        std::vector<int> jacob = generateJacobsthal(pend.size());
        size_t last_jacob = 1;

        for (size_t i = 0; i < jacob.size(); ++i) {
            size_t current_jacob = static_cast<size_t>(jacob[i]);
            if (current_jacob > pend.size()) current_jacob = pend.size();
            
            for (size_t j = current_jacob; j > last_jacob; --j) {
                typename T::value_type item = pend[j - 1];
                typename T::iterator it_end = std::find(main_chain.begin(), main_chain.end(), winners[j - 1]);
                typename T::iterator it_pos = std::lower_bound(main_chain.begin(), it_end, item);
                main_chain.insert(it_pos, item);
            }
            last_jacob = current_jacob;
        }

        if (last_jacob < pend.size()) {
            for (size_t j = pend.size(); j > last_jacob; --j) {
                typename T::value_type item = pend[j - 1];
                typename T::iterator it_end = std::find(main_chain.begin(), main_chain.end(), winners[j - 1]);
                typename T::iterator it_pos = std::lower_bound(main_chain.begin(), it_end, item);
                main_chain.insert(it_pos, item);
            }
        }

        if (hasStraggler) {
            typename T::iterator it_pos = std::lower_bound(main_chain.begin(), main_chain.end(), straggler);
            main_chain.insert(it_pos, straggler);
        }
        container = main_chain;
    }

public:
    template <typename T>
    static double execute(int argc, char** argv, T& container) {
        container.clear();
        parseInput(argc, argv, container);
        std::clock_t start = std::clock();
        sort(container);
        std::clock_t end = std::clock();
        return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    }
    static void printBefore(int argc, char **argv);
};

#endif